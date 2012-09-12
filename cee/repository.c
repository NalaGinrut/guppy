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
#include <string.h>
#include <git2.h>
#include "repository.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GIT_DEFAULT_CACHE_SIZE
#define GIT_DEFAULT_CACHE_SIZE 128
#endif // End of GIT_DEFAULT_CACHE_SIZE;
  
scm_t_bits scm_git_repository_tag;

#define SCM_ASSERT_REPOSITORY(x) \
  scm_assert_smob_type(scm_git_repository_tag ,(x))

static int scm_git_repository_printer(SCM repo_smob ,SCM port ,scm_print_state *pstate);
static scm_sizet scm_git_repository_free(SCM repo);
static SCM scm_repository2scm(git_repository *gr);

static int scm_git_repository_printer(SCM repo_smob ,SCM port ,scm_print_state *pstate)
{}
  
static scm_sizet scm_git_repository_free(SCM repo)
{
  // TODO: call git_repository_free to free the ptr in Smob.
}

static SCM scm_repository2scm(git_repository *gr)
{
  SCM_RETURN_NEWSMOB(scm_git_repository_tag ,gr);
}

SCM scm_mmr_git_repository_open(SCM repo ,SCM repo_name)
#define FUNC_NAME "inner-git-repository-open"
{
  git_repository *r = NULL;
  char *name = NULL;

  SCM_ASSERT_REPOSITORY(repo);
  SCM_VALIDATE_STRING(2 ,repo_name);

  r = (git_repository*)SCM_SMOB_DATA(repo);
  name = scm_to_locale_string(repo_name);

  git_repository_open(&r ,name);

  free(name);

  SCM_RETURN_NEWSMOB(scm_git_repository_tag ,r);
}
#undef FUNC_NAME

SCM scm_mmr_git_repository_index(SCM index ,SCM repo)
#define FUNC_NAME "inner-git-repository-index"
{
  git_repository *r = NULL;
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(index);
  SCM_ASSERT_REPOSITORY(repo);

  r = (git_repository*)SCM_SMOB_DATA(repo);
  i = (git_index*)SCM_SMOB_DATA(index);

  git_repository_index(&i ,r);
}
#undef FUNC_NAME
  
void mmr_init_repository()
{
  scm_git_repository_tag = scm_make_smob_type("git-repository" ,sizeof(git_repository));
  scm_set_smob_print(scm_git_repository_tag ,scm_git_repository_printer);
  scm_set_smob_free(scm_git_repository_tag ,scm_git_repository_free);

  scm_c_define_gsubr("inner-git-repository-open" ,2 ,0 ,0 ,scm_mmr_git_repository_open);
  scm_c_define_gsubr("inner-git-repository-index" ,2 ,0 ,0 ,scm_mmr_git_repository_index);
}
  
#ifdef __cplusplus
}
#endif
