/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// Qt includes
#include <QDebug>

// CTK includes
#include "ctkRangeSlider.h"
#include "ctkRangeSliderEventPlayer.h"

// ----------------------------------------------------------------------------
ctkRangeSliderEventPlayer::ctkRangeSliderEventPlayer(QObject *parent)
  : pqWidgetEventPlayer(parent)
{

}

// ----------------------------------------------------------------------------
bool ctkRangeSliderEventPlayer::playEvent(QObject *Object,
                                                const QString &Command,
                                                const QString &Arguments,
                                                bool &Error)
{
  if (Command != "set_max_int" && Command != "set_min_int")
    {
    return false;
    }

  const int value = Arguments.toInt();

  if(ctkRangeSlider* const object =
       qobject_cast<ctkRangeSlider*>(Object))
    {
    if (Command == "set_min_int")
      {
      object->setMinimumValue(value);
      return true;
      }
    if (Command == "set_max_int")
      {
      object->setMaximumValue(value);
      return true;
      }
    }

  qCritical() << "calling set_min/max_int on unhandled type " << Object;
  Error = true;
  return true;
}

