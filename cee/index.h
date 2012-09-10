#ifndef __GUPPY_CEE_INDEX_H__
#define __GUPPY_CEE_INDEX_H__
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

#define SCM_ASSERT_GIT_INDEX(x) \
  scm_assert_smob_type(scm_git_index_tag ,(x))

SCM scm_mmr_git_index_read(SCM index);
SCM scm_mmr_git_index_entrycount(SCM index);
SCM git_index_get(SCM index ,SCM n);




#endif // End of __GUPPY_CEE_INDEX_H__;
