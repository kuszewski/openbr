/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright 2012 The MITRE Corporation                                      *
 *                                                                           *
 * Licensed under the Apache License, Version 2.0 (the "License");           *
 * you may not use this file except in compliance with the License.          *
 * You may obtain a copy of the License at                                   *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 * Unless required by applicable law or agreed to in writing, software       *
 * distributed under the License is distributed on an "AS IS" BASIS,         *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
 * See the License for the specific language governing permissions and       *
 * limitations under the License.                                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BEE_BEE_H
#define BEE_BEE_H

#include <QList>
#include <QPair>
#include <QHash>
#include <QString>
#include <QStringList>
#include <opencv2/core/core.hpp>
#include <openbr/openbr_plugin.h>

/*** Functions for parsing BEE style data structures. ***/
namespace BEE
{
    const uchar Match(0xff);
    const uchar NonMatch(0x7f);
    const uchar DontCare(0x00);
    typedef float Simmat_t;
    typedef uchar Mask_t;

    // Sigset
    br::FileList readSigset(const br::File &sigset, bool ignoreMetadata = false);
    void writeSigset(const QString &sigset, const br::FileList &files, bool ignoreMetadata = false);

    // Matrix
    cv::Mat readSimmat(const br::File &simmat, QString *targetSigset = NULL, QString *querySigset = NULL);
    cv::Mat readMask(const br::File &mask);
    void writeSimmat(const cv::Mat &m, const QString &simmat, const QString &targetSigset = "Unknown_Target", const QString &querySigset = "Unknown_Query");
    void writeMask(const cv::Mat &m, const QString &mask, const QString &targetSigset = "Unknown_Target", const QString &querySigset = "Unknown_Query");
    void readMatrixHeader(const QString &matrix, QString *targetSigset, QString *querySigset);
    void writeMatrixHeader(const QString &matrix, const QString &targetSigset, const QString &querySigset);

    // Mask
    void makeMask(const QString &targetInput, const QString &queryInput, const QString &mask);
    cv::Mat makeMask(const br::FileList &targets, const br::FileList &queries, int partition = 0);
    void combineMasks(const QStringList &inputMasks, const QString &outputMask, const QString &method);
}

#endif // BEE_BEE_H
