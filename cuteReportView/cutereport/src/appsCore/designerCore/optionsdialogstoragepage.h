/***************************************************************************
 *   This file is part of the CuteReport project                           *
 *   Copyright (C) 2012-2015 by Alexander Mikhalov                         *
 *   alexander.mikhalov@gmail.com                                          *
 *                                                                         *
 **                   GNU General Public License Usage                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/

#ifndef OPTIONSDIALOGSTORAGEPAGE_H
#define OPTIONSDIALOGSTORAGEPAGE_H

#include "optionsdialog.h"

#include <QPointer>

namespace Ui {
class OptionsDialogStoragePage;
}

namespace CuteDesigner {
class Core;
}

namespace CuteReport {
class StorageHelperInterface;
class StorageInterface;
}

class QTreeWidgetItem;

class OptionsDialogStoragePage : public OptionsDialogPageInterface
{
    Q_OBJECT
    
public:
    explicit OptionsDialogStoragePage(CuteDesigner::Core * core);
    ~OptionsDialogStoragePage();

    virtual void activate();
    virtual void deactivate();
    
    QListWidgetItem * createButton(QListWidget * listWidget);

private slots:
    void storagesListIndexChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    void setNewStorageModule();
    void deleteCurrentStorage();
    void setDefaultStorage();
    void clearDefaultStorage();
    void updateStorageList();

private:
    Ui::OptionsDialogStoragePage *ui;
    CuteDesigner::Core * m_core;
    QPointer<CuteReport::StorageHelperInterface> m_currentStorageHelper;
};

#endif // OPTIONSDIALOGSTORAGEPAGE_H
