/*
 * Copyright (C) 2017 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alberto Aguirre <alberto.aguirre@canonical.com>
 *
 */

#ifndef MULTIPASS_SIMPLE_STREAMS_MANIFEST_H
#define MULTIPASS_SIMPLE_STREAMS_MANIFEST_H

#include <multipass/vm_image_info.h>

#include <QByteArray>
#include <QMap>
#include <QString>

#include <memory>
#include <vector>

namespace multipass
{

class SimpleStreamsManifest
{
public:
    SimpleStreamsManifest(SimpleStreamsManifest&&) = default;
    SimpleStreamsManifest& operator=(SimpleStreamsManifest&&) = default;

    static std::unique_ptr<SimpleStreamsManifest> fromJson(QByteArray json);
    const QString updated_at;
    const std::vector<VMImageInfo> products;
    const QMap<QString, const VMImageInfo*> image_records;

protected:
    SimpleStreamsManifest(const SimpleStreamsManifest&) = delete;
    SimpleStreamsManifest& operator=(const SimpleStreamsManifest&) = delete;
};
}
#endif // MULTIPASS_SIMPLE_STREAMS_MANIFEST_H
