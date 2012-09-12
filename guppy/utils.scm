;;  Copyright (C) 2012
;;      "Mu Lei" known as "NalaGinrut" <mulei@gnu.org>
;;  Guppy is free software: you can redistribute it and/or modify
;;  it under the terms of the GNU Lesser General Public License(LGPL) as published by
;;  the Free Software Foundation, or (at your option) any later version.

;;  Guppy is distributed in the hope that it will be useful,
;;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;  GNU General Public License for more details.

;;  You should have received a copy of the GNU Lesser General Public License
;;  along with this program.  If not, see <http://www.gnu.org/licenses/>.

(define-module (guppy utils))

(module-export-all! (current-module))

(dynamic-call "init_guppy_cee_module" (dynamic-link "libguppy-cee"))



