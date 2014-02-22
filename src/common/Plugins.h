/* $Id: Plugins.h 3453 2013-02-01 18:36:49Z IMPOMEZIA $
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

#ifndef PLUGINS_H_
#define PLUGINS_H_

#include <QHash>
#include <QObject>
#include <QPluginLoader>
#include <QStringList>
#include <QVariant>

#include "plugins/CoreApi.h"
#include "tools/Ver.h"

class CoreApi;

/*!
 * Загружает плагин и хранит о нём информацию.
 */
class SCHAT_EXPORT PluginItem
{
public:
  PluginItem(const QString &fileName);
  ~PluginItem();
  inline bool isLoaded() const             { return m_loaded; }
  inline bool isValid() const              { return m_valid; }
  inline const QVariantMap& header() const { return m_header; }
  inline QObject *plugin()                 { return m_plugin; }
  inline QString id() const                { return m_header.value(CORE_API_ID).toString(); }
  inline void setLoaded(bool loaded)       { m_loaded = loaded; }
  QString icon() const;

private:
  bool m_loaded;          ///< \b true если загружено целевое API.
  bool m_valid;           ///< \b true если плагин содержит корректный CoreApi.
  QObject *m_plugin;      ///< Объект плагина.
  QPluginLoader m_loader; ///< Загрузчик плагина.
  QVariantMap m_header;   ///< Заголовок плагина.
};


/*!
 * Базовый класс, обеспечивающий загрузку плагинов.
 */
class SCHAT_EXPORT Plugins : public QObject
{
  Q_OBJECT

public:
  Plugins(QObject *parent = 0);
  ~Plugins();

  inline const QString& type() const           { return m_type; }
  inline PluginItem *plugin(const QString &id) { return m_plugins.value(id); }
  inline void setType(const QString &type)     { m_type = type; }
  QList<PluginItem *> list() const;
  void load();

protected:
  virtual void init() {}

  QHash<QString, PluginItem *> m_plugins;   ///< Таблица плагинов.
  QString m_min;                            ///< Минимальная совместимая версия.
  QString m_type;                           ///< Тип плагинов, загрузка которых разрешена.
  QStringList m_sorted;                     ///< Сортированный список плагинов, этот список определяет очерёдность загрузки наследниками этого класса.

private:
  bool check(PluginItem *plugin);
  void load(const QString &path);
};

#endif /* PLUGINS_H_ */
