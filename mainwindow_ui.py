# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(743, 832)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setMaximumSize(QtCore.QSize(2000, 3000))
        self.centralwidget.setObjectName("centralwidget")
        self.sensormotorWidget = QtWidgets.QWidget(self.centralwidget)
        self.sensormotorWidget.setGeometry(QtCore.QRect(80, 20, 576, 676))
        self.sensormotorWidget.setObjectName("sensormotorWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.sensormotorWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.tempWidget = QtWidgets.QWidget(self.sensormotorWidget)
        self.tempWidget.setObjectName("tempWidget")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.tempWidget)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_3 = QtWidgets.QLabel(self.tempWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_3.sizePolicy().hasHeightForWidth())
        self.label_3.setSizePolicy(sizePolicy)
        self.label_3.setMinimumSize(QtCore.QSize(120, 0))
        self.label_3.setMaximumSize(QtCore.QSize(120, 16777215))
        self.label_3.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_3.setTextFormat(QtCore.Qt.PlainText)
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_3.addWidget(self.label_3)
        self.temp_lcd = QtWidgets.QLCDNumber(self.tempWidget)
        self.temp_lcd.setMinimumSize(QtCore.QSize(70, 0))
        self.temp_lcd.setMaximumSize(QtCore.QSize(16777215, 30))
        self.temp_lcd.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.temp_lcd.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.temp_lcd.setSmallDecimalPoint(False)
        self.temp_lcd.setDigitCount(4)
        self.temp_lcd.setSegmentStyle(QtWidgets.QLCDNumber.Flat)
        self.temp_lcd.setObjectName("temp_lcd")
        self.horizontalLayout_3.addWidget(self.temp_lcd)
        self.temp_plotView = PlotWidget(self.tempWidget)
        self.temp_plotView.setObjectName("temp_plotView")
        self.horizontalLayout_3.addWidget(self.temp_plotView)
        self.verticalLayout.addWidget(self.tempWidget)
        self.line = QtWidgets.QFrame(self.sensormotorWidget)
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.verticalLayout.addWidget(self.line)
        self.irWidget = QtWidgets.QWidget(self.sensormotorWidget)
        self.irWidget.setObjectName("irWidget")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout(self.irWidget)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_4 = QtWidgets.QLabel(self.irWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setMinimumSize(QtCore.QSize(120, 0))
        self.label_4.setMaximumSize(QtCore.QSize(120, 16777215))
        self.label_4.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_4.setTextFormat(QtCore.Qt.PlainText)
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_4.addWidget(self.label_4)
        self.ir_lcd = QtWidgets.QLCDNumber(self.irWidget)
        self.ir_lcd.setMinimumSize(QtCore.QSize(70, 0))
        self.ir_lcd.setMaximumSize(QtCore.QSize(16777215, 30))
        self.ir_lcd.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.ir_lcd.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.ir_lcd.setSmallDecimalPoint(False)
        self.ir_lcd.setDigitCount(4)
        self.ir_lcd.setSegmentStyle(QtWidgets.QLCDNumber.Flat)
        self.ir_lcd.setObjectName("ir_lcd")
        self.horizontalLayout_4.addWidget(self.ir_lcd)
        self.ir_plotView = PlotWidget(self.irWidget)
        self.ir_plotView.setObjectName("ir_plotView")
        self.horizontalLayout_4.addWidget(self.ir_plotView)
        self.verticalLayout.addWidget(self.irWidget)
        self.line_3 = QtWidgets.QFrame(self.sensormotorWidget)
        self.line_3.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.verticalLayout.addWidget(self.line_3)
        self.forceWidget = QtWidgets.QWidget(self.sensormotorWidget)
        self.forceWidget.setObjectName("forceWidget")
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout(self.forceWidget)
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.label_12 = QtWidgets.QLabel(self.forceWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_12.sizePolicy().hasHeightForWidth())
        self.label_12.setSizePolicy(sizePolicy)
        self.label_12.setMinimumSize(QtCore.QSize(120, 0))
        self.label_12.setMaximumSize(QtCore.QSize(120, 16777215))
        self.label_12.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_12.setTextFormat(QtCore.Qt.PlainText)
        self.label_12.setAlignment(QtCore.Qt.AlignCenter)
        self.label_12.setObjectName("label_12")
        self.horizontalLayout_7.addWidget(self.label_12)
        self.force_lcd = QtWidgets.QLCDNumber(self.forceWidget)
        self.force_lcd.setMinimumSize(QtCore.QSize(70, 0))
        self.force_lcd.setMaximumSize(QtCore.QSize(16777215, 30))
        self.force_lcd.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.force_lcd.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.force_lcd.setSmallDecimalPoint(False)
        self.force_lcd.setDigitCount(4)
        self.force_lcd.setSegmentStyle(QtWidgets.QLCDNumber.Flat)
        self.force_lcd.setObjectName("force_lcd")
        self.horizontalLayout_7.addWidget(self.force_lcd)
        self.force_plotView = PlotWidget(self.forceWidget)
        self.force_plotView.setObjectName("force_plotView")
        self.horizontalLayout_7.addWidget(self.force_plotView)
        self.verticalLayout.addWidget(self.forceWidget)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 743, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_3.setText(_translate("MainWindow", "Temp. Sensor\n"
" (C)"))
        self.label_4.setText(_translate("MainWindow", "IR Sensor\n"
"(cm)"))
        self.label_12.setText(_translate("MainWindow", "Force Sensor\n"
" (N)"))
from pyqtgraph import PlotWidget
