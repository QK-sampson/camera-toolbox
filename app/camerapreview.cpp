/*
 * This file is part of Camera Toolbox.
 *   (https://github.com/rlamarche/camera-toolbox)
 * Copyright (c) 2016 Romain Lamarche.
 *
 * Camera Toolbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * Camera Toolbox is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "camerapreview.h"

using namespace hpis;

CameraPreview::CameraPreview(QByteArray &data, QString mimetype) : m_data(data), m_mimetype(mimetype)
{

}


const QByteArray CameraPreview::data()
{
    return m_data;
}

QString CameraPreview::mimetype()
{
    return m_mimetype;
}
