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

SCM scm_mmr_git_oid_fmt(SCM string ,SCM oid)
#define FUNC_NAME "inner-git-oid-fmt"
{
  char *str = NULL;
  size_t i;
  size_t cnt = 0;
  git_oid *o = NULL;
  SCM ret;
  
  SCM_VALIDATE_STRING(string);
  SCM_ASSERT_OID(oid);

  o = (git_oid*)SCM_SMOB_DATA(oid);
  cnt = sizeof(o->id);
  str = (char*)malloc(cnt+1);
  
  for (i = 0 ;i < cnt ;i++)
    str = fmt_one(str ,oid->id[i]);

  ret = scm_from_locale_string(str);
  free(str);

  return ret;
}
#undef FUNC_NAME

#ifdef __cplusplus
}
#endif
