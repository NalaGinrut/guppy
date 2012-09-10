#ifndef __GUPPY_CEE_REPOSITORY_H__
#define __GUPPY_CEE_REPOSITIRY_H__
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

#define SCM_ASSERT_REPOSITORY(x) \
  scm_assert_smob_type(scm_git_repository_tag ,(x))

SCM scm_repository2scm(scm_rag_epoll_event_set *ees);
SCM scm_mmr_git_repository_open(SCM repo ,SCM repo_name);
SCM scm_mmr_git_repository_index(SCM index ,SCM repo);

#endif // End of __GUPPY_CEE_REPOSITORY_H__;
