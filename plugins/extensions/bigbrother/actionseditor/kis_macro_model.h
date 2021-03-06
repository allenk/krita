/* This file is part of the KDE project
 * Copyright (c) 2009 Cyrille Berger <cberger@cberger.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef _KIS_MACRO_MODEL_H_
#define _KIS_MACRO_MODEL_H_

#include <QAbstractListModel>

class KisRecordedAction;
class KisMacro;

class KisMacroModel : public QAbstractListModel
{
public:
    KisMacroModel(KisMacro*);
    ~KisMacroModel() override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex()) override;
    void addAction(const QModelIndex& _after, const KisRecordedAction& _action);
    void duplicateAction(const QModelIndex& index);
    void raise(const QModelIndex& index);
    void lower(const QModelIndex& index);
private:
    KisMacro* m_macro;
};


#endif
