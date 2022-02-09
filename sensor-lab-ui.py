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
        # setup initial value and GUI 
        self.setupUi(self)
        self.temp_value = 0
        self.ir_value = 0
        self.force_value = 0

        self.time_axis = list(range(100))  # 100 time points
        self.temp_data = [0] * 100  
        self.ir_data = [0] * 100  
        self.force_data = [0] * 100 

        self.temp_plotView.setBackground('w')
        self.ir_plotView.setBackground('w')
        self.force_plotView.setBackground('w')

        pen = pg.mkPen(color=(255, 0, 0))
        self.temp_data_line =  self.temp_plotView.plot(self.time_axis, self.ir_data, pen=pen)
        self.ir_data_line =  self.ir_plotView.plot(self.time_axis, self.ir_data, pen=pen)
        self.force_data_line =  self.force_plotView.plot(self.time_axis, self.force_data, pen=pen)

        self.serial = QtSerialPort.QSerialPort(
            '/dev/tty.usbmodem144101',
            baudRate = QtSerialPort.QSerialPort.Baud9600,     
            dataBits = QtSerialPort.QSerialPort.Data8,
            readyRead = self.receive
        )
        self.serial.open(QtCore.QIODevice.ReadWrite)

        self.timer = QtCore.QTimer()
        self.timer.setInterval(50)
        self.timer.timeout.connect(self.update_plot_data)
        self.timer.start()


    @QtCore.pyqtSlot()
    def receive(self):
        while self.serial.canReadLine():
            ino_data = self.serial.readLine().data().decode()
            ino_text = ino_data.rstrip('\r\n')
            print(ino_text)
            # ino_text = re.findall(r"<sensor\(T(\d+);I(\d+);F(\d+)\)>", ino_text)
            ino_data_array = re.findall(r"(\d+)", ino_text)
            print(ino_data_array)
            self.temp_value = int(ino_data_array[0])
            self.ir_value = int(ino_data_array[1])
            self.force_value = int(ino_data_array[2])

    def update_plot_data(self):

        self.time_axis = self.time_axis[1:]  # Remove the first y element.
        self.time_axis.append(self.time_axis[-1] + 1)  # Add a new value 1 higher than the last.

        self.temp_data = self.temp_data[1:]  # Remove the first
        self.temp_data.append(self.temp_value)  # Add a new random value.
        self.temp_data_line.setData(self.time_axis, self.temp_data)  # Update the data.

        self.ir_data = self.ir_data[1:]  # Remove the first
        self.ir_data.append(self.ir_value)  # Add a new random value.
        self.ir_data_line.setData(self.time_axis, self.ir_data)  # Update the data.

        self.force_data = self.force_data[1:]  # Remove the first
        self.force_data.append(self.force_value)  # Add a new random value.
        self.force_data_line.setData(self.time_axis, self.force_data)  # Update the data.



if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec())