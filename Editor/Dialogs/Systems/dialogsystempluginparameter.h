/*
    RPG Paper Maker Copyright (C) 2017-2020 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#ifndef DIALOGSYSTEMPLUGINPARAMETER_H
#define DIALOGSYSTEMPLUGINPARAMETER_H

#include <QDialog>
#include "systempluginparameter.h"

// -------------------------------------------------------
//
//  CLASS DialogSystemPluginParameter
//
//  A dialog used for editing the model of a system plugin parameter.
//
// -------------------------------------------------------

namespace Ui {
class DialogSystemPluginParameter;
}

class DialogSystemPluginParameter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSystemPluginParameter(SystemPluginParameter &parameter,
        QWidget *parent = nullptr);
    ~DialogSystemPluginParameter();

    void initialize();

private:
    Ui::DialogSystemPluginParameter *ui;

    SystemPluginParameter &m_parameter;
};

#endif // DIALOGSYSTEMPLUGINPARAMETER_H