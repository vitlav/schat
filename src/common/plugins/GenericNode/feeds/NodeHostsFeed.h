/* $Id: NodeHostsFeed.h 3735 2013-07-07 23:38:33Z IMPOMEZIA $
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

#ifndef NODEHOSTSFEED_H_
#define NODEHOSTSFEED_H_

#include "feeds/Feed.h"
#include "feeds/FeedCreator.h"

/*!
 * Серверная реализация фида \b hosts.
 */
class NodeHostsFeed : public Feed
{
public:
  NodeHostsFeed(const QString &name, const QVariantMap &data);
  NodeHostsFeed(const QString &name = FEED_NAME_HOSTS, qint64 date = 0);

  FeedReply del(const QString &path, Channel *channel = 0, const QByteArray &blob = QByteArray());
  FeedReply post(const QString &path, const QVariantMap &json, Channel *channel = 0, const QByteArray &blob = QByteArray());
  FeedReply put(const QString &path, const QVariantMap &json, Channel *channel = 0, const QByteArray &blob = QByteArray());
  QVariantMap feed(Channel *channel = 0) const;
};


class NodeHostsFeedCreator : public FeedCreator
{
public:
  Feed* create(const QString &name) const;
  Feed* load(const QString &name, const QVariantMap &data) const;
  inline QString name() const { return FEED_NAME_HOSTS; }
};

#endif /* NODEHOSTSFEED_H_ */
