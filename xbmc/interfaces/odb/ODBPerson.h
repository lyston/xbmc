/*
*      Copyright (C) 2017 Team Kodi
*      https://kodi.tv
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#ifndef ODBPERSON_H
#define ODBPERSON_H

#include <odb/core.hxx>

#include "ODBArt.h"

#include <string>

PRAGMA_DB (model version(1, 1, open))

PRAGMA_DB (object pointer(std::shared_ptr) \
                  table("person"))
class CODBPerson
{
public:
  CODBPerson()
  {
    m_name = "";
    m_sortName = "";
    m_synced = false;
  };
  
PRAGMA_DB (id auto)
  unsigned long m_idPerson;
PRAGMA_DB (type("VARCHAR(255)"))
  std::string m_name;
  std::string m_sortName;
  odb::lazy_shared_ptr<CODBArt> m_art;
  
  //Members not stored in the db, used for sync ...
PRAGMA_DB (transient)
  bool m_synced;
  
private:
  friend class odb::access;
  
PRAGMA_DB (index member(m_name))
  
};

#endif /* ODBPERSON_H */