/*	
 *  Copyright (C) 2012
 *	"Mu Lei" known as "NalaGinrut" <mulei@gnu.org>
 
 *  Guppy is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 
 *  Guppy is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <libguile.h>
#include <git2.h>
#include "index.h"
#include "guppy_struct.h"

#ifdef __cplusplus
extern "C" {
#endif

scm_t_bits scm_git_index_tag;
scm_t_bits scm_git_index_entry_tag;

// NOTE: It's only a SCM-POINTER. You need to parse the index_time structure with Scheme code.
static inline SCM scm_mmr_from_index_time(git_index_time time)
{
  return scm_from_pointer((void*)&time);
}
  
SCM scm_mmr_git_index_read(SCM index)
#define FUNC_NAME "inner-git-index-read"
{
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(index);

  i = (git_index*)SCM_SMOB_DATA(index);

  return scm_from_int(git_index_read(*i));
}
#undef FUNC_NAME

SCM scm_mmr_git_index_write(SCM index)
#define FUNC_NAME "inner-git-index-write"
{
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(index);

  i = (git_index*)SCM_SMOB_DATA(index);

  return scm_from_int(git_index_write(*i));
}
#undef FUNC_NAME

SCM scm_mmr_git_index_entrycount(SCM index)
#define FUNC_NAME "inner-git-index-entrycount"
{
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(index);

  i = (git_index*)SCM_SMOB_DATA(index);

  return scm_from_int(git_index_entrycount(*i));
}
#undef FUNC_NAME

SCM git_index_entrycount_unmerged(git_index *index)
#define FUNC_NAME "inner-git-index-entrycount-unmerged"
{
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(index);

  i = (git_index*)SCM_SMOB_DATA(index);

  return scm_from_int(git_index_entrycount_unmerged(*i));
}
#undef FUNC_NAME
  
SCM scm_mmr_git_index_get(SCM index ,SCM n)
#define FUNC_NAME "inner-git-index-get"
{
  git_index *i = NULL;
  size_t c = 0;
  git_index_entry *e = NULL;
    
  SCM_ASSERT_GIT_INDEX(index);
  SCM_VALIDATE_NUMBER(2 ,n);
  
  i = (git_index*)SCM_SMOB_DATA(index);
  c = scm_from_int(n);
  
  e = git_index_get(i ,c);

  SCM_RETURN_NEWSMOB(scm_git_index_entry_tag ,e);
}
#undef FUNC_NAME

  /* git_index_entry struct from libgit2/include/git2/index.h
    typedef struct git_index_entry {
    git_index_time ctime;
    git_index_time mtime;

    unsigned int dev;
    unsigned int ino;
    unsigned int mode;
    unsigned int uid;
    unsigned int gid;
    git_off_t file_size;

    git_oid oid;

    unsigned short flags;
    unsigned short flags_extended;

    char *path;
    } git_index_entry;
  */

// index entry 
SCM_MMR_OBJ_GETTER(index_entry ,ctime ,ctime ,scm_mmr_from_index_time);
SCM_MMR_OBJ_GETTER(index_entry ,mtime ,mtime ,scm_mmr_from_index_time);
SCM_MMR_OBJ_GETTER(index_entry ,dev ,dev ,scm_from_uint);
SCM_MMR_OBJ_GETTER(index_entry ,ino ,ino ,scm_from_uint);
SCM_MMR_OBJ_GETTER(index_entry ,mode ,mode ,scm_from_uint);
SCM_MMR_OBJ_GETTER(index_entry ,uid ,uid ,scm_from_uint);
SCM_MMR_OBJ_GETTER(index_entry ,oid ,oid ,scm_from_uint64);
SCM_MMR_OBJ_GETTER(index_entry ,flags ,flags ,scm_from_uint16);
SCM_MMR_OBJ_GETTER(index_entry ,flagse ,flagse ,scm_from_uint16);
SCM_MMR_OBJ_GETTER(index_entry ,path ,path ,scm_from_locale_string);

void mmr_init_index()
{
  scm_c_define_gsubr("inner-git-index-read" ,1 ,0 ,0 ,scm_mmr_git_index_read);
  scm_c_define_gsubr("inner-git-index-entrycount" ,1 ,0 ,0 ,scm_mmr_git_index_entrycount);
  scm_c_define_gsubr("inner-git-index-get" ,2 ,0 ,0 ,scm_mmr_git_index_read);
}

#ifdef __cplusplus
}
#endif
