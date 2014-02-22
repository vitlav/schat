/* $Id: YouTubeFilter.h 3650 2013-04-21 00:21:16Z IMPOMEZIA $
 * IMPOMEZIA Simple Chat
 * Copyright © 2008-2013 IMPOMEZIA <schat@impomezia.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef YOUTUBEFILTER_H_
#define YOUTUBEFILTER_H_

#include "text/TokenFilter.h"

class YouTubeFilter : public AbstractFilter
{
public:
  YouTubeFilter();
  bool filter(QList<HtmlToken> &tokens, int options = 0) const;

private:
  void make(QList<HtmlToken> &tokens, const QString &text) const;

  QStringList m_hosts;
};

#endif /* YOUTUBEFILTER_H_ */
