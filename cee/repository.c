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

#ifdef __cplusplus
extern "C" {
#endif

scm_t_bits scm_git_repository_tag;

#define SCM_ASSERT_REPOSITORY(x) \
  scm_assert_smob_type(scm_git_repository_tag ,(x))

static git_repository *repository_alloc(void)；

SCM scm_repository2scm(scm_rag_epoll_event_set *ees)
{
  SCM_RETURN_NEWSMOB(rag_epoll_event_set_tag ,ees);
}

SCM scm_mmr_git_repository_open(SCM repo ,SCM repo_name)
#define FUNC_NAME "inner-git-repository-open"
{
  git_repository *r = NULL;
  char *name = NULL;

  SCM_ASSERT_REPOSITORY(r);
  SCM_VALIDATE_STRING(repo_name);

  r = (git_repository*)SCM_SMOB_DATA(repo);
  name = scm_to_locale_string(repo_name);

  git_repository_open(r ,name);

  free(name);

  SCM_RETURN_NEWSMOB(scm_git_repository_tag ,r);
}
#undef FUNC_NAME

SCM scm_mmr_git_repository_index(SCM index ,SCM repo)
#define FUNC_NAME "inner-git-repository-index"
{
  git_repository *r = NULL;
  git_index *i = NULL;

  SCM_ASSERT_GIT_INDEX(i);
  SCM_ASSERT_REPOSITORY(r);

  r = (git_repository*)SCM_SMOB_DATA(repo);
  i = (git_index*)SCM_SMOB_DATA(index);

  git_repository_index(i ,r);
}
#undef FUNC_NAME

  
static git_repository *repository_alloc(void)
{
  git_repository *repo = scm_gc_malloc(sizeof(git_repository) ,"repository");
  
  if (!repo)
    return NULL;

  memset(repo ,0x0 ,sizeof(git_repository));

  if(git_cache_init(&repo->objects ,GIT_DEFAULT_CACHE_SIZE ,&git_object__free) < 0)
    {
      git__free(repo);
      return NULL;
    }

  /* set all the entries in the cvar cache to `unset` */
  git_repository__cvar_cache_clear(repo);

  return repo;
}
  
#ifdef __cplusplus
}
#endif
