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

#include "gpcamerapreview.h"

#include <QDebug>

uint32_t fixBytesOrder(uint32_t val)
{
    return  ((0xff000000 & val) >> 24) |
            ((0x00ff0000 & val) >> 8) |
            ((0x0000ff00 & val) << 8) |
            ((0x000000ff & val) << 24);
}

uint16_t fixBytesOrder(uint16_t val)
{
    return (val >> 8) | (val << 8);
}

uint8_t fixBytesOrder(uint8_t val)
{
    return val;
}


void fixBytesOrder(NikonLiveViewHeader* lvHeader)
{


    lvHeader->jpg_width = fixBytesOrder(lvHeader->jpg_width);
    lvHeader->jpg_height = fixBytesOrder(lvHeader->jpg_height);

    lvHeader->width = fixBytesOrder(lvHeader->width);
    lvHeader->height = fixBytesOrder(lvHeader->height);

    lvHeader->display_width = fixBytesOrder(lvHeader->display_width);
    lvHeader->display_height = fixBytesOrder(lvHeader->display_height);

    lvHeader->center_x = fixBytesOrder(lvHeader->center_x);
    lvHeader->center_y = fixBytesOrder(lvHeader->center_y);

    lvHeader->af_width = fixBytesOrder(lvHeader->af_width);
    lvHeader->af_height = fixBytesOrder(lvHeader->af_height);

    lvHeader->af_center_x = fixBytesOrder(lvHeader->af_center_x);
    lvHeader->af_center_y = fixBytesOrder(lvHeader->af_center_y);

    lvHeader->reserved_01 = fixBytesOrder(lvHeader->reserved_01);

    lvHeader->focus_area = fixBytesOrder(lvHeader->focus_area);
    lvHeader->rotation_direction = fixBytesOrder(lvHeader->rotation_direction);

    lvHeader->focus_driving_status = fixBytesOrder(lvHeader->focus_driving_status);

    lvHeader->reserved_02 = fixBytesOrder(lvHeader->reserved_02);
    lvHeader->reserved_03 = fixBytesOrder(lvHeader->reserved_03);
    lvHeader->reserved_04 = fixBytesOrder(lvHeader->reserved_04);

    lvHeader->countdown_time = fixBytesOrder(lvHeader->countdown_time);

    lvHeader->focusing_judgement_result = fixBytesOrder(lvHeader->focusing_judgement_result);
    lvHeader->af_driving_enabled_status = fixBytesOrder(lvHeader->af_driving_enabled_status);

    lvHeader->reserved_05 = fixBytesOrder(lvHeader->reserved_05);

    lvHeader->rolling = fixBytesOrder(lvHeader->rolling);
    lvHeader->pitching = fixBytesOrder(lvHeader->pitching);
    lvHeader->yawing = fixBytesOrder(lvHeader->yawing);

    lvHeader->remaining_time_movie_recording = fixBytesOrder(lvHeader->remaining_time_movie_recording);
    lvHeader->movie_recording = fixBytesOrder(lvHeader->movie_recording);

    lvHeader->af_mode_face_detection_status = fixBytesOrder(lvHeader->af_mode_face_detection_status);
    lvHeader->nb_detected_faces = fixBytesOrder(lvHeader->nb_detected_faces);

    lvHeader->af_area = fixBytesOrder(lvHeader->af_area);


    lvHeader->detected_face_width_01 = fixBytesOrder(lvHeader->detected_face_width_01);
    lvHeader->detected_face_height_01 = fixBytesOrder(lvHeader->detected_face_height_01);
    lvHeader->detected_face_center_x_01 = fixBytesOrder(lvHeader->detected_face_center_x_01);
    lvHeader->detected_face_center_y_01 = fixBytesOrder(lvHeader->detected_face_center_y_01);

    lvHeader->detected_face_width_02 = fixBytesOrder(lvHeader->detected_face_width_02);
    lvHeader->detected_face_height_02 = fixBytesOrder(lvHeader->detected_face_height_02);
    lvHeader->detected_face_center_x_02 = fixBytesOrder(lvHeader->detected_face_center_x_02);
    lvHeader->detected_face_center_y_02 = fixBytesOrder(lvHeader->detected_face_center_y_02);

    lvHeader->detected_face_width_03 = fixBytesOrder(lvHeader->detected_face_width_03);
    lvHeader->detected_face_height_03 = fixBytesOrder(lvHeader->detected_face_height_03);
    lvHeader->detected_face_center_x_03 = fixBytesOrder(lvHeader->detected_face_center_x_03);
    lvHeader->detected_face_center_y_03 = fixBytesOrder(lvHeader->detected_face_center_y_03);

    lvHeader->detected_face_width_04 = fixBytesOrder(lvHeader->detected_face_width_04);
    lvHeader->detected_face_height_04 = fixBytesOrder(lvHeader->detected_face_height_04);
    lvHeader->detected_face_center_x_04 = fixBytesOrder(lvHeader->detected_face_center_x_04);
    lvHeader->detected_face_center_y_04 = fixBytesOrder(lvHeader->detected_face_center_y_04);

    lvHeader->detected_face_width_05 = fixBytesOrder(lvHeader->detected_face_width_05);
    lvHeader->detected_face_height_05 = fixBytesOrder(lvHeader->detected_face_height_05);
    lvHeader->detected_face_center_x_05 = fixBytesOrder(lvHeader->detected_face_center_x_05);
    lvHeader->detected_face_center_y_05 = fixBytesOrder(lvHeader->detected_face_center_y_05);

    lvHeader->detected_face_width_06 = fixBytesOrder(lvHeader->detected_face_width_06);
    lvHeader->detected_face_height_06 = fixBytesOrder(lvHeader->detected_face_height_06);
    lvHeader->detected_face_center_x_06 = fixBytesOrder(lvHeader->detected_face_center_x_06);
    lvHeader->detected_face_center_y_06 = fixBytesOrder(lvHeader->detected_face_center_y_06);

    lvHeader->detected_face_width_07 = fixBytesOrder(lvHeader->detected_face_width_07);
    lvHeader->detected_face_height_07 = fixBytesOrder(lvHeader->detected_face_height_07);
    lvHeader->detected_face_center_x_07 = fixBytesOrder(lvHeader->detected_face_center_x_07);
    lvHeader->detected_face_center_y_07 = fixBytesOrder(lvHeader->detected_face_center_y_07);

    lvHeader->detected_face_width_08 = fixBytesOrder(lvHeader->detected_face_width_08);
    lvHeader->detected_face_height_08 = fixBytesOrder(lvHeader->detected_face_height_08);
    lvHeader->detected_face_center_x_08 = fixBytesOrder(lvHeader->detected_face_center_x_08);
    lvHeader->detected_face_center_y_08 = fixBytesOrder(lvHeader->detected_face_center_y_08);

    lvHeader->detected_face_width_09 = fixBytesOrder(lvHeader->detected_face_width_09);
    lvHeader->detected_face_height_09 = fixBytesOrder(lvHeader->detected_face_height_09);
    lvHeader->detected_face_center_x_09 = fixBytesOrder(lvHeader->detected_face_center_x_09);
    lvHeader->detected_face_center_y_09 = fixBytesOrder(lvHeader->detected_face_center_y_09);

    lvHeader->detected_face_width_10 = fixBytesOrder(lvHeader->detected_face_width_10);
    lvHeader->detected_face_height_10 = fixBytesOrder(lvHeader->detected_face_height_10);
    lvHeader->detected_face_center_x_10 = fixBytesOrder(lvHeader->detected_face_center_x_10);
    lvHeader->detected_face_center_y_10 = fixBytesOrder(lvHeader->detected_face_center_y_10);

    lvHeader->detected_face_width_11 = fixBytesOrder(lvHeader->detected_face_width_11);
    lvHeader->detected_face_height_11 = fixBytesOrder(lvHeader->detected_face_height_11);
    lvHeader->detected_face_center_x_11 = fixBytesOrder(lvHeader->detected_face_center_x_11);
    lvHeader->detected_face_center_y_11 = fixBytesOrder(lvHeader->detected_face_center_y_11);

    lvHeader->detected_face_width_12 = fixBytesOrder(lvHeader->detected_face_width_12);
    lvHeader->detected_face_height_12 = fixBytesOrder(lvHeader->detected_face_height_12);
    lvHeader->detected_face_center_x_12 = fixBytesOrder(lvHeader->detected_face_center_x_12);
    lvHeader->detected_face_center_y_12 = fixBytesOrder(lvHeader->detected_face_center_y_12);

    lvHeader->detected_face_width_13 = fixBytesOrder(lvHeader->detected_face_width_13);
    lvHeader->detected_face_height_13 = fixBytesOrder(lvHeader->detected_face_height_13);
    lvHeader->detected_face_center_x_13 = fixBytesOrder(lvHeader->detected_face_center_x_13);
    lvHeader->detected_face_center_y_13 = fixBytesOrder(lvHeader->detected_face_center_y_13);

    lvHeader->detected_face_width_14 = fixBytesOrder(lvHeader->detected_face_width_14);
    lvHeader->detected_face_height_14 = fixBytesOrder(lvHeader->detected_face_height_14);
    lvHeader->detected_face_center_x_14 = fixBytesOrder(lvHeader->detected_face_center_x_14);
    lvHeader->detected_face_center_y_14 = fixBytesOrder(lvHeader->detected_face_center_y_14);

    lvHeader->detected_face_width_15 = fixBytesOrder(lvHeader->detected_face_width_15);
    lvHeader->detected_face_height_15 = fixBytesOrder(lvHeader->detected_face_height_15);
    lvHeader->detected_face_center_x_15 = fixBytesOrder(lvHeader->detected_face_center_x_15);
    lvHeader->detected_face_center_y_15 = fixBytesOrder(lvHeader->detected_face_center_y_15);

    lvHeader->detected_face_width_16 = fixBytesOrder(lvHeader->detected_face_width_16);
    lvHeader->detected_face_height_16 = fixBytesOrder(lvHeader->detected_face_height_16);
    lvHeader->detected_face_center_x_16 = fixBytesOrder(lvHeader->detected_face_center_x_16);
    lvHeader->detected_face_center_y_16 = fixBytesOrder(lvHeader->detected_face_center_y_16);

    lvHeader->detected_face_width_17 = fixBytesOrder(lvHeader->detected_face_width_17);
    lvHeader->detected_face_height_17 = fixBytesOrder(lvHeader->detected_face_height_17);
    lvHeader->detected_face_center_x_17 = fixBytesOrder(lvHeader->detected_face_center_x_17);
    lvHeader->detected_face_center_y_17 = fixBytesOrder(lvHeader->detected_face_center_y_17);

    lvHeader->detected_face_width_18 = fixBytesOrder(lvHeader->detected_face_width_18);
    lvHeader->detected_face_height_18 = fixBytesOrder(lvHeader->detected_face_height_18);
    lvHeader->detected_face_center_x_18 = fixBytesOrder(lvHeader->detected_face_center_x_18);
    lvHeader->detected_face_center_y_18 = fixBytesOrder(lvHeader->detected_face_center_y_18);

    lvHeader->detected_face_width_19 = fixBytesOrder(lvHeader->detected_face_width_19);
    lvHeader->detected_face_height_19 = fixBytesOrder(lvHeader->detected_face_height_19);
    lvHeader->detected_face_center_x_19 = fixBytesOrder(lvHeader->detected_face_center_x_19);
    lvHeader->detected_face_center_y_19 = fixBytesOrder(lvHeader->detected_face_center_y_19);

    lvHeader->detected_face_width_20 = fixBytesOrder(lvHeader->detected_face_width_20);
    lvHeader->detected_face_height_20 = fixBytesOrder(lvHeader->detected_face_height_20);
    lvHeader->detected_face_center_x_20 = fixBytesOrder(lvHeader->detected_face_center_x_20);
    lvHeader->detected_face_center_y_20 = fixBytesOrder(lvHeader->detected_face_center_y_20);

    lvHeader->detected_face_width_21 = fixBytesOrder(lvHeader->detected_face_width_21);
    lvHeader->detected_face_height_21 = fixBytesOrder(lvHeader->detected_face_height_21);
    lvHeader->detected_face_center_x_21 = fixBytesOrder(lvHeader->detected_face_center_x_21);
    lvHeader->detected_face_center_y_21 = fixBytesOrder(lvHeader->detected_face_center_y_21);

    lvHeader->detected_face_width_22 = fixBytesOrder(lvHeader->detected_face_width_22);
    lvHeader->detected_face_height_22 = fixBytesOrder(lvHeader->detected_face_height_22);
    lvHeader->detected_face_center_x_22 = fixBytesOrder(lvHeader->detected_face_center_x_22);
    lvHeader->detected_face_center_y_22 = fixBytesOrder(lvHeader->detected_face_center_y_22);

    lvHeader->detected_face_width_23 = fixBytesOrder(lvHeader->detected_face_width_23);
    lvHeader->detected_face_height_23 = fixBytesOrder(lvHeader->detected_face_height_23);
    lvHeader->detected_face_center_x_23 = fixBytesOrder(lvHeader->detected_face_center_x_23);
    lvHeader->detected_face_center_y_23 = fixBytesOrder(lvHeader->detected_face_center_y_23);

    lvHeader->detected_face_width_24 = fixBytesOrder(lvHeader->detected_face_width_24);
    lvHeader->detected_face_height_24 = fixBytesOrder(lvHeader->detected_face_height_24);
    lvHeader->detected_face_center_x_24 = fixBytesOrder(lvHeader->detected_face_center_x_24);
    lvHeader->detected_face_center_y_24 = fixBytesOrder(lvHeader->detected_face_center_y_24);

    lvHeader->detected_face_width_25 = fixBytesOrder(lvHeader->detected_face_width_25);
    lvHeader->detected_face_height_25 = fixBytesOrder(lvHeader->detected_face_height_25);
    lvHeader->detected_face_center_x_25 = fixBytesOrder(lvHeader->detected_face_center_x_25);
    lvHeader->detected_face_center_y_25 = fixBytesOrder(lvHeader->detected_face_center_y_25);

    lvHeader->detected_face_width_26 = fixBytesOrder(lvHeader->detected_face_width_26);
    lvHeader->detected_face_height_26 = fixBytesOrder(lvHeader->detected_face_height_26);
    lvHeader->detected_face_center_x_26 = fixBytesOrder(lvHeader->detected_face_center_x_26);
    lvHeader->detected_face_center_y_26 = fixBytesOrder(lvHeader->detected_face_center_y_26);

    lvHeader->detected_face_width_27 = fixBytesOrder(lvHeader->detected_face_width_27);
    lvHeader->detected_face_height_27 = fixBytesOrder(lvHeader->detected_face_height_27);
    lvHeader->detected_face_center_x_27 = fixBytesOrder(lvHeader->detected_face_center_x_27);
    lvHeader->detected_face_center_y_27 = fixBytesOrder(lvHeader->detected_face_center_y_27);

    lvHeader->detected_face_width_28 = fixBytesOrder(lvHeader->detected_face_width_28);
    lvHeader->detected_face_height_28 = fixBytesOrder(lvHeader->detected_face_height_28);
    lvHeader->detected_face_center_x_28 = fixBytesOrder(lvHeader->detected_face_center_x_28);
    lvHeader->detected_face_center_y_28 = fixBytesOrder(lvHeader->detected_face_center_y_28);

    lvHeader->detected_face_width_29 = fixBytesOrder(lvHeader->detected_face_width_29);
    lvHeader->detected_face_height_29 = fixBytesOrder(lvHeader->detected_face_height_29);
    lvHeader->detected_face_center_x_29 = fixBytesOrder(lvHeader->detected_face_center_x_29);
    lvHeader->detected_face_center_y_29 = fixBytesOrder(lvHeader->detected_face_center_y_29);

    lvHeader->detected_face_width_30 = fixBytesOrder(lvHeader->detected_face_width_30);
    lvHeader->detected_face_height_30 = fixBytesOrder(lvHeader->detected_face_height_30);
    lvHeader->detected_face_center_x_30 = fixBytesOrder(lvHeader->detected_face_center_x_30);
    lvHeader->detected_face_center_y_30 = fixBytesOrder(lvHeader->detected_face_center_y_30);

    lvHeader->detected_face_width_31 = fixBytesOrder(lvHeader->detected_face_width_31);
    lvHeader->detected_face_height_31 = fixBytesOrder(lvHeader->detected_face_height_31);
    lvHeader->detected_face_center_x_31 = fixBytesOrder(lvHeader->detected_face_center_x_31);
    lvHeader->detected_face_center_y_31 = fixBytesOrder(lvHeader->detected_face_center_y_31);

    lvHeader->detected_face_width_32 = fixBytesOrder(lvHeader->detected_face_width_32);
    lvHeader->detected_face_height_32 = fixBytesOrder(lvHeader->detected_face_height_32);
    lvHeader->detected_face_center_x_32 = fixBytesOrder(lvHeader->detected_face_center_x_32);
    lvHeader->detected_face_center_y_32 = fixBytesOrder(lvHeader->detected_face_center_y_32);

    lvHeader->detected_face_width_33 = fixBytesOrder(lvHeader->detected_face_width_33);
    lvHeader->detected_face_height_33 = fixBytesOrder(lvHeader->detected_face_height_33);
    lvHeader->detected_face_center_x_33 = fixBytesOrder(lvHeader->detected_face_center_x_33);
    lvHeader->detected_face_center_y_33 = fixBytesOrder(lvHeader->detected_face_center_y_33);

    lvHeader->detected_face_width_34 = fixBytesOrder(lvHeader->detected_face_width_34);
    lvHeader->detected_face_height_34 = fixBytesOrder(lvHeader->detected_face_height_34);
    lvHeader->detected_face_center_x_34 = fixBytesOrder(lvHeader->detected_face_center_x_34);
    lvHeader->detected_face_center_y_34 = fixBytesOrder(lvHeader->detected_face_center_y_34);

    lvHeader->detected_face_width_35 = fixBytesOrder(lvHeader->detected_face_width_35);
    lvHeader->detected_face_height_35 = fixBytesOrder(lvHeader->detected_face_height_35);
    lvHeader->detected_face_center_x_35 = fixBytesOrder(lvHeader->detected_face_center_x_35);
    lvHeader->detected_face_center_y_35 = fixBytesOrder(lvHeader->detected_face_center_y_35);

    lvHeader->sound_indicator_peak_l = fixBytesOrder(lvHeader->sound_indicator_peak_l);
    lvHeader->sound_indicator_peak_r = fixBytesOrder(lvHeader->sound_indicator_peak_r);

    lvHeader->sound_indicator_current_l = fixBytesOrder(lvHeader->sound_indicator_current_l);
    lvHeader->sound_indicator_current_r = fixBytesOrder(lvHeader->sound_indicator_current_r);

    lvHeader->reserved_06 = fixBytesOrder(lvHeader->reserved_06);

    lvHeader->use_white_balance = fixBytesOrder(lvHeader->use_white_balance);

    lvHeader->reserved_07 = fixBytesOrder(lvHeader->reserved_07);
    lvHeader->reserved_08 = fixBytesOrder(lvHeader->reserved_08);
    lvHeader->reserved_09 = fixBytesOrder(lvHeader->reserved_09);
    lvHeader->reserved_10 = fixBytesOrder(lvHeader->reserved_10);
    lvHeader->reserved_11 = fixBytesOrder(lvHeader->reserved_11);
    lvHeader->reserved_12 = fixBytesOrder(lvHeader->reserved_12);
    lvHeader->reserved_13 = fixBytesOrder(lvHeader->reserved_13);
    lvHeader->reserved_14 = fixBytesOrder(lvHeader->reserved_14);

    lvHeader->reserved_15 = fixBytesOrder(lvHeader->reserved_15);
}

GPCameraPreview::GPCameraPreview(CameraFile* cameraFile) : CameraPreview(), m_cameraFile(cameraFile)
{
    gp_file_ref(m_cameraFile);
    gp_file_get_data_and_size(m_cameraFile, &m_data, &m_size);

    m_nikonLvHeader = *((NikonLiveViewHeader*) m_data);
    fixBytesOrder(&m_nikonLvHeader);

    unsigned char *data, *jpgStartPtr = NULL, *jpgEndPtr = NULL;
    uint32_t size = m_size;


    m_data = m_data + 384;

    if (false) {
        data = (unsigned char*) m_data;

        /* look for the JPEG SOI marker (0xFFD8) in data */
        jpgStartPtr = (unsigned char*)memchr(data, 0xff, size);
        while(jpgStartPtr && ((jpgStartPtr+1) < (data + size))) {
            if(*(jpgStartPtr + 1) == 0xd8) { /* SOI found */
                break;
            } else { /* go on looking (starting at next byte) */
                jpgStartPtr++;
                jpgStartPtr = (unsigned char*)memchr(jpgStartPtr, 0xff, data + size - jpgStartPtr);
            }
        }
        if(!jpgStartPtr) { /* no SOI -> no JPEG */
            // TODO
        }
        /* if SOI found, start looking for EOI marker (0xFFD9) one byte after SOI
           (just to be sure we will not go beyond the end of the data array) */
        jpgEndPtr = (unsigned char*)memchr(jpgStartPtr+1, 0xff, data+size-jpgStartPtr-1);
        while(jpgEndPtr && ((jpgEndPtr+1) < (data + size))) {
            if(*(jpgEndPtr + 1) == 0xd9) { /* EOI found */
                jpgEndPtr += 2;
                break;
            } else { /* go on looking (starting at next byte) */
                jpgEndPtr++;
                jpgEndPtr = (unsigned char*)memchr(jpgEndPtr, 0xff, data + size - jpgEndPtr);
            }
        }
        if(!jpgEndPtr) { /* no EOI -> no JPEG */
            // TODO
        }

        m_data = (char*)jpgStartPtr;
        m_size = jpgEndPtr-jpgStartPtr;

        qInfo() << jpgStartPtr - data;
    }
    /*
    (char*)jpgStartPtr, jpgEndPtr-jpgStartPtr
*/

    // 248 qInfo() << sizeof(NikonLiveViewHeader);
    /*
    QString str;
    uint32_t val = 0x11223344;
    uint32_t val2 = fixBytesOrder(val);
    str.sprintf("%04x -> %04x", val, val2);
    qInfo() << str;*/
//    qInfo() << m_nikonLiveViewData.jpg_width;
//    qInfo() << m_nikonLiveViewData.width;
}

GPCameraPreview::GPCameraPreview(const GPCameraPreview &copy)
{
    m_cameraFile = copy.m_cameraFile;
    m_data = copy.m_data;
    m_size = copy.m_size;

    gp_file_ref(m_cameraFile);
}

GPCameraPreview::~GPCameraPreview()
{
    gp_file_unref(m_cameraFile);
}


const char* GPCameraPreview::data()
{
    return m_data;
}

unsigned long GPCameraPreview::size()
{
    return m_size;
}

CameraPreview::Format GPCameraPreview::format()
{
    return CameraPreview::FormatJPG;
}
