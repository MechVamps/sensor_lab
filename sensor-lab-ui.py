from PyQt5 import QtWidgets, QtCore, QtSerialPort 
from PyQt5.QtWidgets import (QWidget, QPushButton,
        QFrame, QApplication)
from pyqtgraph import PlotWidget, plot
import pyqtgraph as pg
import sys  # We need sys so that we can pass argv to QApplication
import os
from random import randint
# from ui_form import Ui_Widget
from mainwindow_ui import Ui_MainWindow
import re # to remove gibberish letter or symbol bytes in serial port data 

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    
    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.setupUi(self)

        self.x = list(range(100))  # 100 time points
        self.y = [randint(0,100) for _ in range(100)]  # 100 data points
        self.force_value = 0
        self.force_PlotView.setBackground('w')

        pen = pg.mkPen(color=(255, 0, 0))
        self.data_line =  self.force_PlotView.plot(self.x, self.y, pen=pen)

        self.serial = QtSerialPort.QSerialPort(
            '/dev/tty.usbmodem141201',
            # baudRate = QtSerialPort.QSerialPort.Baud9600,     
            # dataBits = QtSerialPort.QSerialPort.Data8,
            readyRead=self.receive
        )
        self.serial.setBaudRate(9600)
        self.serial.open(QtCore.QIODevice.ReadWrite)

        self.timer = QtCore.QTimer()
        self.timer.setInterval(50)
        self.timer.timeout.connect(self.update_plot_data)
        self.timer.start()
        
    @QtCore.pyqtSlot()
    def receive(self):
        while self.serial.canReadLine():
            text = self.serial.readLine().data().decode()
            text = text.rstrip('\r\n')
            force_value_txt = re.findall(r'\d+', text)
            if force_value_txt != []:
                self.force_value = int(force_value_txt[0])
            else: 
                self.force_value = 0
            self.force_lcd.setDigitCount(4)
            self.force_lcd.display(self.force_value)
            print(self.force_value)

    # @QtCore.pyqtSlot()
    # def send(self):
    #     self.serial.write(self.message_le.text().encode())

    # @QtCore.pyqtSlot(bool)
    # def on_toggled(self, checked):
    #     self.button.setText("Disconnect" if checked else "Connect")
    #     if checked:
    #         if not self.serial.isOpen():
    #             if not self.serial.open(QtCore.QIODevice.ReadWrite):
    #                 self.button.setChecked(False)
    #     else:
    #         self.serial.close()

    def update_plot_data(self):

        self.x = self.x[1:]  # Remove the first y element.
        self.x.append(self.x[-1] + 1)  # Add a new value 1 higher than the last.

        self.y = self.y[1:]  # Remove the first
        self.y.append(self.force_value)  # Add a new random value.

        self.data_line.setData(self.x, self.y)  # Update the data.



if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec())