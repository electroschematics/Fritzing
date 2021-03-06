/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2011 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5868 $:
$Author: cohen@irascible.com $:
$Date: 2012-02-15 11:06:03 -0800 (Wed, 15 Feb 2012) $

********************************************************************/

#ifndef PAD_H
#define PAD_H

#include <QRectF>
#include <QPainterPath>
#include <QPixmap>
#include <QVariant>
#include <QCheckBox>
#include <QComboBox>
#include <QTextEdit>

#include "resizableboard.h"

class Pad : public ResizableBoard 
{
	Q_OBJECT

public:
	// after calling this constructor if you want to render the loaded svg (either from model or from file), MUST call <renderImage>
	Pad(ModelPart *, ViewIdentifierClass::ViewIdentifier, const ViewGeometry & viewGeometry, long id, QMenu * itemMenu, bool doLabel);
	~Pad();

	QString retrieveSvg(ViewLayer::ViewLayerID, QHash<QString, QString> & svgHash, bool blackOnly, double dpi);
	bool collectExtraInfo(QWidget * parent, const QString & family, const QString & prop, const QString & value, bool swappingEnabled, QString & returnProp, QString & returnValue, QWidget * & returnWidget);
	bool canEditPart();
	void setProp(const QString & prop, const QString & value);
	bool hasPartLabel();
	bool stickyEnabled();
	PluralType isPlural();
	bool rotationAllowed();
	bool rotation45Allowed();
	bool freeRotationAllowed(Qt::KeyboardModifiers);	
	bool hasPartNumberProperty();
	void setInitialSize();
	void mousePressEvent(QGraphicsSceneMouseEvent * event );
	void mouseMoveEvent(QGraphicsSceneMouseEvent * event );
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * event );
	void paintSelected(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void hoverEnterEvent(QGraphicsSceneHoverEvent * event );
	void hoverLeaveEvent(QGraphicsSceneHoverEvent * event );
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event );
	void addedToScene(bool temporary);
	void paintHover(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected slots:
	void terminalPointEntry(const QString &);

protected:
	double minWidth();
	double minHeight();
	ViewIdentifierClass::ViewIdentifier theViewIdentifier();
	QString makeLayerSvg(ViewLayer::ViewLayerID viewLayerID, double mmW, double mmH, double milsW, double milsH);
	QString makeFirstLayerSvg(double mmW, double mmH, double milsW, double milsH);
	QString makeNextLayerSvg(ViewLayer::ViewLayerID, double mmW, double mmH, double milsW, double milsH);
	void resizeMMAux(double w, double h);
	ResizableBoard::Corner findCorner(QPointF, Qt::KeyboardModifiers);

};



#endif
