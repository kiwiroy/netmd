/*
 * boblight
 * Copyright (C) Bob  2009 
 * 
 * boblight is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * boblight is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CCONDITION
#define CCONDITION

#include <stdint.h>
#include "mutex.h"

//pthread condition variable class
class CCondition : public CMutex
{
  public:
    CCondition();
    ~CCondition();

    void Signal();
    void Broadcast();
    bool Wait(int64_t usecs = -1);

  private:
    pthread_cond_t m_cond;    
};

#endif //CCONDITION