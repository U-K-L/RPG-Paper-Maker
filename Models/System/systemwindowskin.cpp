/*
    RPG Paper Maker Copyright (C) 2017-2018 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dialogsystemwindowskin.h"
#include "rpm.h"

const QString SystemWindowSkin::JSON_PICTURE_ID = "pid";
const QString SystemWindowSkin::JSON_TOP_LEFT = "tl";
const QString SystemWindowSkin::JSON_TOP_RIGHT= "tr";
const QString SystemWindowSkin::JSON_BOT_LEFT= "bl";
const QString SystemWindowSkin::JSON_BOT_RIGHT= "br";
const QString SystemWindowSkin::JSON_LEFT= "l";
const QString SystemWindowSkin::JSON_RIGHT= "r";
const QString SystemWindowSkin::JSON_TOP= "t";
const QString SystemWindowSkin::JSON_BOT= "b";
const QString SystemWindowSkin::JSON_BACKGROUND= "back";
const QString SystemWindowSkin::JSON_BACKGROUND_REPEAT= "backr";
const QString SystemWindowSkin::JSON_ARROW_END_MESSAGE= "aem";
const QString SystemWindowSkin::JSON_ARROW_TARGET_SELECTION= "ats";
const QString SystemWindowSkin::JSON_ARROW_UP_DOWN= "aud";
const QString SystemWindowSkin::JSON_TEXT_NORMAL= "tn";
const QString SystemWindowSkin::JSON_TEXT_CRITICAL= "tc";
const QString SystemWindowSkin::JSON_TEXT_HEAL= "th";
const QString SystemWindowSkin::JSON_TEXT_MISS= "tm";

// -------------------------------------------------------
//
//  CONSTRUCTOR / DESTRUCTOR / GET / SET
//
// -------------------------------------------------------


SystemWindowSkin::SystemWindowSkin() :
    SystemWindowSkin(-1, "", -1, QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), QRect(0,
    0, 1, 1), QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), QRect(0,
    0, 1, 1), QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), true, QRect(0, 0, 1, 1),
    QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), QRect(0, 0, 1, 1), QRect(0, 0, 1, 1),
    QRect(0, 0, 1, 1), QRect(0, 0, 1, 1))
{

}

SystemWindowSkin::SystemWindowSkin(int i, QString n, int pictureID, QRectF
    topLeft, QRectF topRight, QRectF botLeft, QRectF botRight, QRectF left,
    QRectF right, QRectF top, QRectF bot, QRectF background, bool
    backgroundRepeat, QRectF arrowEndMessage, QRectF arrowTargetSelection,
    QRectF arrowUpDown, QRectF textNormal, QRectF textCritical, QRectF textHeal,
    QRectF textMiss) :
    SuperListItem (i, n),
    m_pictureID(pictureID),
    m_topLeft(topLeft),
    m_topRight(topRight),
    m_botLeft(botLeft),
    m_botRight(botRight),
    m_left(left),
    m_right(right),
    m_top(top),
    m_bot(bot),
    m_background(background),
    m_backgroudRepeat(backgroundRepeat),
    m_arrowEndMessage(arrowEndMessage),
    m_arrowTargetSelection(arrowTargetSelection),
    m_arrowUpDown(arrowUpDown),
    m_textNormal(textNormal),
    m_textCritical(textCritical),
    m_textHeal(textHeal),
    m_textMiss(textMiss)
{

}

SystemWindowSkin::~SystemWindowSkin()
{

}

int SystemWindowSkin::pictureID() const {
    return m_pictureID;
}

void SystemWindowSkin::setPictureID(int id) {
    m_pictureID = id;
}

QRectF * SystemWindowSkin::topLeft() {
    return &m_topLeft;
}

QRectF * SystemWindowSkin::topRight() {
    return &m_topRight;
}

QRectF * SystemWindowSkin::botLeft() {
    return &m_botLeft;
}

QRectF * SystemWindowSkin::botRight() {
    return &m_botRight;
}

QRectF * SystemWindowSkin::left() {
    return &m_left;
}

QRectF * SystemWindowSkin::right() {
    return &m_right;
}

QRectF * SystemWindowSkin::top() {
    return &m_top;
}

QRectF * SystemWindowSkin::bot() {
    return &m_bot;
}

QRectF * SystemWindowSkin::background() {
    return &m_background;
}

bool SystemWindowSkin::backgroudRepeat() {
    return m_backgroudRepeat;
}

QRectF * SystemWindowSkin::arrowEndMessage() {
    return &m_arrowEndMessage;
}

QRectF * SystemWindowSkin::arrowTargetSelection() {
    return &m_arrowTargetSelection;
}

QRectF * SystemWindowSkin::arrowUpDown() {
    return &m_arrowUpDown;
}

QRectF * SystemWindowSkin::textNormal() {
    return &m_textNormal;
}

QRectF * SystemWindowSkin::textCritical() {
    return &m_textCritical;
}

QRectF * SystemWindowSkin::textHeal() {
    return &m_textHeal;
}

QRectF * SystemWindowSkin::textMiss() {
    return &m_textMiss;
}

// -------------------------------------------------------
//
//  VIRTUAL
//
// -------------------------------------------------------

bool SystemWindowSkin::openDialog() {
    SystemWindowSkin windowSkin;
    windowSkin.setCopy(*this);
    DialogSystemWindowSkin dialog(windowSkin);
    if (dialog.exec() == QDialog::Accepted){
        setCopy(windowSkin);
        return true;
    }
    return false;
}

// -------------------------------------------------------

SuperListItem* SystemWindowSkin::createCopy() const {
    SystemWindowSkin* super = new SystemWindowSkin;
    super->setCopy(*this);
    return super;
}

// -------------------------------------------------------

void SystemWindowSkin::setCopy(const SystemWindowSkin& super) {
    SuperListItem::setCopy(super);

    m_pictureID = super.m_pictureID;
    m_topLeft = super.m_topLeft;
    m_topRight = super.m_topRight;
    m_botLeft = super.m_botLeft;
    m_botRight = super.m_botRight;
    m_left = super.m_left;
    m_right = super.m_right;
    m_top = super.m_top;
    m_bot = super.m_bot;
    m_background = super.m_background;
    m_backgroudRepeat = super.m_backgroudRepeat;
    m_arrowEndMessage = super.m_arrowEndMessage;
    m_arrowTargetSelection = super.m_arrowTargetSelection;
    m_arrowUpDown = super.m_arrowUpDown;
    m_textNormal = super.m_textNormal;
    m_textCritical = super.m_textCritical;
    m_textHeal = super.m_textHeal;
    m_textMiss = super.m_textMiss;
}

// -------------------------------------------------------

void SystemWindowSkin::read(const QJsonObject &json) {
    SuperListItem::read(json);
    QJsonArray tab;

    m_pictureID = json[JSON_PICTURE_ID].toInt();

    tab = json[JSON_TOP_LEFT].toArray();
    RPM::readRectF(tab, m_topLeft);
    tab = json[JSON_TOP_RIGHT].toArray();
    RPM::readRectF(tab, m_topRight);
    tab = json[JSON_BOT_LEFT].toArray();
    RPM::readRectF(tab, m_botLeft);
    tab = json[JSON_BOT_RIGHT].toArray();
    RPM::readRectF(tab, m_botRight);
    tab = json[JSON_LEFT].toArray();
    RPM::readRectF(tab, m_left);
    tab = json[JSON_RIGHT].toArray();
    RPM::readRectF(tab, m_right);
    tab = json[JSON_TOP].toArray();
    RPM::readRectF(tab, m_top);
    tab = json[JSON_BOT].toArray();
    RPM::readRectF(tab, m_bot);
    tab = json[JSON_BACKGROUND].toArray();
    RPM::readRectF(tab, m_background);
    m_backgroudRepeat = json[JSON_BACKGROUND_REPEAT].toBool();
    tab = json[JSON_ARROW_END_MESSAGE].toArray();
    RPM::readRectF(tab, m_arrowEndMessage);
    tab = json[JSON_ARROW_TARGET_SELECTION].toArray();
    RPM::readRectF(tab, m_arrowTargetSelection);
    tab = json[JSON_ARROW_UP_DOWN].toArray();
    RPM::readRectF(tab, m_arrowUpDown);
    tab = json[JSON_TEXT_NORMAL].toArray();
    RPM::readRectF(tab, m_textNormal);
    tab = json[JSON_TEXT_CRITICAL].toArray();
    RPM::readRectF(tab, m_textCritical);
    tab = json[JSON_TEXT_HEAL].toArray();
    RPM::readRectF(tab, m_textHeal);
    tab = json[JSON_TEXT_MISS].toArray();
    RPM::readRectF(tab, m_textMiss);
}

// -------------------------------------------------------

void SystemWindowSkin::write(QJsonObject &json) const {
    SuperListItem::write(json);
    QJsonArray tab;

    json[JSON_PICTURE_ID] = m_pictureID;

    RPM::writeRectF(tab, m_topLeft);
    json[JSON_TOP_LEFT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_topRight);
    json[JSON_TOP_RIGHT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_botLeft);
    json[JSON_BOT_LEFT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_botRight);
    json[JSON_BOT_RIGHT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_left);
    json[JSON_LEFT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_right);
    json[JSON_RIGHT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_top);
    json[JSON_TOP] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_bot);
    json[JSON_BOT] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_background);
    json[JSON_BACKGROUND] = tab;
    tab = QJsonArray();
    json[JSON_BACKGROUND_REPEAT] = m_backgroudRepeat;
    RPM::writeRectF(tab, m_arrowEndMessage);
    json[JSON_ARROW_END_MESSAGE] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_arrowTargetSelection);
    json[JSON_ARROW_TARGET_SELECTION] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_arrowUpDown);
    json[JSON_ARROW_UP_DOWN] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_textNormal);
    json[JSON_TEXT_NORMAL] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_textCritical);
    json[JSON_TEXT_CRITICAL] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_textHeal);
    json[JSON_TEXT_HEAL] = tab;
    tab = QJsonArray();
    RPM::writeRectF(tab, m_textMiss);
    json[JSON_TEXT_MISS] = tab;
}
