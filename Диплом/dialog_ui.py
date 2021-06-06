import excel_control
from PyQt5 import QtCore, QtGui, QtWidgets


class UiDialog(excel_control.ExcelControl):
    def __init__(self, dialog):
        """Конструктор класса UiDialog"""
        super(UiDialog, self).__init__()
        self.dialog = dialog
        dialog.setObjectName("Dialog")
        dialog.resize(1411, 565)
        size_policy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        size_policy.setHorizontalStretch(141)
        size_policy.setVerticalStretch(56)
        size_policy.setHeightForWidth(dialog.sizePolicy().hasHeightForWidth())
        dialog.setSizePolicy(size_policy)
        dialog.setMinimumSize(QtCore.QSize(1411, 565))
        dialog.setMaximumSize(QtCore.QSize(1411, 565))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("Изображения/free-icon-binder-4624080.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        dialog.setWindowIcon(icon)
        dialog.setSizeGripEnabled(False)
        dialog.setModal(False)
        self.gridLayout_4 = QtWidgets.QGridLayout(dialog)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.course_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.course_label_d.setFont(font)
        self.course_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.course_label_d.setObjectName("course_label_d")
        self.gridLayout.addWidget(self.course_label_d, 0, 3, 1, 1)
        self.loe_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.loe_combo_box_d.setFont(font)
        self.loe_combo_box_d.setObjectName("loe_combo_box_b")
        self.loe_combo_box_d.addItem("")
        self.loe_combo_box_d.addItem("")
        self.loe_combo_box_d.addItem("")
        self.loe_combo_box_d.addItem("")
        self.loe_combo_box_d.addItem("")
        self.loe_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.loe_combo_box_d, 1, 0, 1, 1)
        self.direction_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.direction_combo_box_d.setFont(font)
        self.direction_combo_box_d.setObjectName("direction_combo_box_d")
        self.direction_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.direction_combo_box_d, 1, 1, 1, 1)
        self.direction_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.direction_label_d.setFont(font)
        self.direction_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.direction_label_d.setObjectName("direction_label_d")
        self.gridLayout.addWidget(self.direction_label_d, 0, 1, 1, 1)
        self.foe_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foe_combo_box_d.setFont(font)
        self.foe_combo_box_d.setObjectName("foe_combo_box_d")
        self.foe_combo_box_d.addItem("")
        self.foe_combo_box_d.addItem("")
        self.foe_combo_box_d.addItem("")
        self.foe_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.foe_combo_box_d, 1, 2, 1, 1)
        self.course_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.course_combo_box_d.setFont(font)
        self.course_combo_box_d.setObjectName("course_combo_box_d")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.course_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.course_combo_box_d, 1, 3, 1, 1)
        self.loe_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.loe_label_d.setFont(font)
        self.loe_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.loe_label_d.setObjectName("loe_label_d")
        self.gridLayout.addWidget(self.loe_label_d, 0, 0, 1, 1)
        self.for_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.for_label_d.setFont(font)
        self.for_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.for_label_d.setObjectName("for_label_d")
        self.gridLayout.addWidget(self.for_label_d, 0, 2, 1, 1)
        self.year_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.year_label_d.setFont(font)
        self.year_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.year_label_d.setObjectName("year_label_d")
        self.gridLayout.addWidget(self.year_label_d, 0, 4, 1, 1)
        self.month_label_d = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.month_label_d.setFont(font)
        self.month_label_d.setAlignment(QtCore.Qt.AlignCenter)
        self.month_label_d.setObjectName("month_label_d")
        self.gridLayout.addWidget(self.month_label_d, 0, 5, 1, 1)
        self.year_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.year_combo_box_d.setFont(font)
        self.year_combo_box_d.setObjectName("year_combo_box_d")
        self.year_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.year_combo_box_d, 1, 4, 1, 1)
        self.month_combo_box_d = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.month_combo_box_d.setFont(font)
        self.month_combo_box_d.setObjectName("month_combo_box_d")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.month_combo_box_d.addItem("")
        self.gridLayout.addWidget(self.month_combo_box_d, 1, 5, 1, 1)
        self.gridLayout_4.addLayout(self.gridLayout, 0, 0, 1, 4)
        self.line_2 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_2.setFont(font)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_2.setLineWidth(1)
        self.line_2.setMidLineWidth(0)
        self.line_2.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_2.setObjectName("line_2")
        self.gridLayout_4.addWidget(self.line_2, 1, 3, 1, 1)
        self.line_4 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_4.setFont(font)
        self.line_4.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_4.setLineWidth(1)
        self.line_4.setMidLineWidth(0)
        self.line_4.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_4.setObjectName("line_4")
        self.gridLayout_4.addWidget(self.line_4, 3, 3, 1, 1)
        self.line = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line.setFont(font)
        self.line.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line.setLineWidth(1)
        self.line.setMidLineWidth(0)
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setObjectName("line")
        self.gridLayout_4.addWidget(self.line, 1, 1, 1, 1)
        self.gridLayout_2 = QtWidgets.QGridLayout()
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.line_8 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_8.setFont(font)
        self.line_8.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_8.setLineWidth(1)
        self.line_8.setMidLineWidth(0)
        self.line_8.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_8.setObjectName("line_8")
        self.gridLayout_2.addWidget(self.line_8, 11, 0, 1, 1)
        self.enrollment_all_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.enrollment_all_check_box_d.setFont(font)
        self.enrollment_all_check_box_d.setTristate(False)
        self.enrollment_all_check_box_d.setObjectName("enrollment_all_check_box_d")
        self.gridLayout_2.addWidget(self.enrollment_all_check_box_d, 0, 0, 1, 1)
        self.foreigners_eb_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_eb_check_box_d.setFont(font)
        self.foreigners_eb_check_box_d.setObjectName("foreigners_eb_check_box_d")
        self.gridLayout_2.addWidget(self.foreigners_eb_check_box_d, 10, 0, 1, 1)
        self.foreigners_ea_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_ea_check_box_d.setFont(font)
        self.foreigners_ea_check_box_d.setObjectName("foreigners_ea_check_box_d")
        self.gridLayout_2.addWidget(self.foreigners_ea_check_box_d, 3, 0, 1, 1)
        self.enrollment_paid_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.enrollment_paid_check_box_d.setFont(font)
        self.enrollment_paid_check_box_d.setObjectName("enrollment_paid_check_box_d")
        self.gridLayout_2.addWidget(self.enrollment_paid_check_box_d, 12, 0, 1, 1)
        self.target_ep_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_ep_check_box_d.setFont(font)
        self.target_ep_check_box_d.setObjectName("target_ep_check_box_d")
        self.gridLayout_2.addWidget(self.target_ep_check_box_d, 14, 0, 1, 1)
        self.line_7 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_7.setFont(font)
        self.line_7.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_7.setLineWidth(1)
        self.line_7.setMidLineWidth(0)
        self.line_7.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_7.setObjectName("line_7")
        self.gridLayout_2.addWidget(self.line_7, 4, 0, 1, 1)
        self.disabled_ea_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_ea_check_box_d.setFont(font)
        self.disabled_ea_check_box_d.setObjectName("disabled_ea_check_box_d")
        self.gridLayout_2.addWidget(self.disabled_ea_check_box_d, 1, 0, 1, 1)
        self.foreigners_ep_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_ep_check_box_d.setFont(font)
        self.foreigners_ep_check_box_d.setObjectName("foreigners_ep_check_box_d")
        self.gridLayout_2.addWidget(self.foreigners_ep_check_box_d, 15, 0, 1, 1)
        self.target_ea_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_ea_check_box_d.setFont(font)
        self.target_ea_check_box_d.setObjectName("target_ea_check_box_d")
        self.gridLayout_2.addWidget(self.target_ea_check_box_d, 2, 0, 1, 1)
        self.target_eb_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_eb_check_box_d.setFont(font)
        self.target_eb_check_box_d.setObjectName("target_eb_check_box_d")
        self.gridLayout_2.addWidget(self.target_eb_check_box_d, 7, 0, 1, 1)
        self.disabled_ep_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_ep_check_box_d.setFont(font)
        self.disabled_ep_check_box_d.setObjectName("disabled_ep_check_box_d")
        self.gridLayout_2.addWidget(self.disabled_ep_check_box_d, 13, 0, 1, 1)
        self.enrollment_budget_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.enrollment_budget_check_box_d.setFont(font)
        self.enrollment_budget_check_box_d.setObjectName("enrollment_budget_check_box_d")
        self.gridLayout_2.addWidget(self.enrollment_budget_check_box_d, 5, 0, 1, 1)
        self.disabled_eb_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_eb_check_box_d.setFont(font)
        self.disabled_eb_check_box_d.setObjectName("disabled_eb_check_box_d")
        self.gridLayout_2.addWidget(self.disabled_eb_check_box_d, 6, 0, 1, 1)
        self.gridLayout_4.addLayout(self.gridLayout_2, 2, 1, 1, 1)
        self.continue_button_d = QtWidgets.QPushButton(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.continue_button_d.setFont(font)
        self.continue_button_d.setObjectName("continue_button_d")
        self.gridLayout_4.addWidget(self.continue_button_d, 4, 1, 1, 1)
        self.gridLayout_3 = QtWidgets.QGridLayout()
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.foreigners_da_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_da_check_box_d.setFont(font)
        self.foreigners_da_check_box_d.setObjectName("foreigners_da_check_box_d")
        self.gridLayout_3.addWidget(self.foreigners_da_check_box_d, 3, 0, 1, 1)
        self.deduct_budget_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.deduct_budget_check_box_d.setFont(font)
        self.deduct_budget_check_box_d.setObjectName("deduct_budget_check_box_d")
        self.gridLayout_3.addWidget(self.deduct_budget_check_box_d, 5, 0, 1, 1)
        self.line_9 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_9.setFont(font)
        self.line_9.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_9.setLineWidth(1)
        self.line_9.setMidLineWidth(0)
        self.line_9.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_9.setObjectName("line_9")
        self.gridLayout_3.addWidget(self.line_9, 9, 0, 1, 1)
        self.disabled_db_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_db_check_box_d.setFont(font)
        self.disabled_db_check_box_d.setObjectName("disabled_db_check_box_d")
        self.gridLayout_3.addWidget(self.disabled_db_check_box_d, 6, 0, 1, 1)
        self.target_db_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_db_check_box_d.setFont(font)
        self.target_db_check_box_d.setObjectName("target_db_check_box_d")
        self.gridLayout_3.addWidget(self.target_db_check_box_d, 7, 0, 1, 1)
        self.target_dp_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_dp_check_box_d.setFont(font)
        self.target_dp_check_box_d.setObjectName("target_dp_check_box_d")
        self.gridLayout_3.addWidget(self.target_dp_check_box_d, 12, 0, 1, 1)
        self.foreigners_dp_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_dp_check_box_d.setFont(font)
        self.foreigners_dp_check_box_d.setObjectName("foreigners_dp_check_box_d")
        self.gridLayout_3.addWidget(self.foreigners_dp_check_box_d, 13, 0, 1, 1)
        self.target_da_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.target_da_check_box_d.setFont(font)
        self.target_da_check_box_d.setObjectName("target_da_check_box_d")
        self.gridLayout_3.addWidget(self.target_da_check_box_d, 2, 0, 1, 1)
        self.disabled_dp_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_dp_check_box_d.setFont(font)
        self.disabled_dp_check_box_d.setObjectName("disabled_dp_check_box_d")
        self.gridLayout_3.addWidget(self.disabled_dp_check_box_d, 11, 0, 1, 1)
        self.disabled_da_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.disabled_da_check_box_d.setFont(font)
        self.disabled_da_check_box_d.setObjectName("disabled_da_check_box_d")
        self.gridLayout_3.addWidget(self.disabled_da_check_box_d, 1, 0, 1, 1)
        self.deduct_paid_check_box = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.deduct_paid_check_box.setFont(font)
        self.deduct_paid_check_box.setObjectName("deduct_paid_check_box")
        self.gridLayout_3.addWidget(self.deduct_paid_check_box, 10, 0, 1, 1)
        self.deduct_all_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.deduct_all_check_box_d.setFont(font)
        self.deduct_all_check_box_d.setObjectName("deduct_all_check_box_d")
        self.gridLayout_3.addWidget(self.deduct_all_check_box_d, 0, 0, 1, 1)
        self.foreigners_db_check_box_d = QtWidgets.QCheckBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foreigners_db_check_box_d.setFont(font)
        self.foreigners_db_check_box_d.setObjectName("foreigners_db_check_box_d")
        self.gridLayout_3.addWidget(self.foreigners_db_check_box_d, 8, 0, 1, 1)
        self.line_10 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_10.setFont(font)
        self.line_10.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_10.setLineWidth(1)
        self.line_10.setMidLineWidth(0)
        self.line_10.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_10.setObjectName("line_10")
        self.gridLayout_3.addWidget(self.line_10, 4, 0, 1, 1)
        self.gridLayout_4.addLayout(self.gridLayout_3, 2, 3, 1, 1)
        self.back_button_d = QtWidgets.QPushButton(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.back_button_d.setFont(font)
        self.back_button_d.setObjectName("back_button_d")
        self.gridLayout_4.addWidget(self.back_button_d, 4, 3, 1, 1)
        self.line_3 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_3.setFont(font)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_3.setLineWidth(1)
        self.line_3.setMidLineWidth(0)
        self.line_3.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_3.setObjectName("line_3")
        self.gridLayout_4.addWidget(self.line_3, 3, 1, 1, 1)
        self.line_5 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_5.setFont(font)
        self.line_5.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_5.setLineWidth(1)
        self.line_5.setMidLineWidth(0)
        self.line_5.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_5.setObjectName("line_5")
        self.gridLayout_4.addWidget(self.line_5, 4, 2, 1, 1)
        self.line_6 = QtWidgets.QFrame(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.line_6.setFont(font)
        self.line_6.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_6.setLineWidth(1)
        self.line_6.setMidLineWidth(0)
        self.line_6.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_6.setObjectName("line_6")
        self.gridLayout_4.addWidget(self.line_6, 2, 2, 1, 1)

        self.retranslate_ui(dialog)
        QtCore.QMetaObject.connectSlotsByName(dialog)
        dialog.setTabOrder(self.loe_combo_box_d, self.direction_combo_box_d)
        dialog.setTabOrder(self.direction_combo_box_d, self.foe_combo_box_d)
        dialog.setTabOrder(self.foe_combo_box_d, self.course_combo_box_d)
        dialog.setTabOrder(self.course_combo_box_d, self.year_combo_box_d)
        dialog.setTabOrder(self.year_combo_box_d, self.month_combo_box_d)
        dialog.setTabOrder(self.month_combo_box_d, self.enrollment_all_check_box_d)
        dialog.setTabOrder(self.enrollment_all_check_box_d, self.disabled_ea_check_box_d)
        dialog.setTabOrder(self.disabled_ea_check_box_d, self.target_ea_check_box_d)
        dialog.setTabOrder(self.target_ea_check_box_d, self.foreigners_ea_check_box_d)
        dialog.setTabOrder(self.foreigners_ea_check_box_d, self.enrollment_budget_check_box_d)
        dialog.setTabOrder(self.enrollment_budget_check_box_d, self.disabled_eb_check_box_d)
        dialog.setTabOrder(self.disabled_eb_check_box_d, self.target_eb_check_box_d)
        dialog.setTabOrder(self.target_eb_check_box_d, self.foreigners_eb_check_box_d)
        dialog.setTabOrder(self.foreigners_eb_check_box_d, self.enrollment_paid_check_box_d)
        dialog.setTabOrder(self.enrollment_paid_check_box_d, self.disabled_ep_check_box_d)
        dialog.setTabOrder(self.disabled_ep_check_box_d, self.target_ep_check_box_d)
        dialog.setTabOrder(self.target_ep_check_box_d, self.foreigners_ep_check_box_d)
        dialog.setTabOrder(self.foreigners_ep_check_box_d, self.deduct_all_check_box_d)
        dialog.setTabOrder(self.deduct_all_check_box_d, self.disabled_da_check_box_d)
        dialog.setTabOrder(self.disabled_da_check_box_d, self.target_da_check_box_d)
        dialog.setTabOrder(self.target_da_check_box_d, self.foreigners_da_check_box_d)
        dialog.setTabOrder(self.foreigners_da_check_box_d, self.deduct_budget_check_box_d)
        dialog.setTabOrder(self.deduct_budget_check_box_d, self.disabled_db_check_box_d)
        dialog.setTabOrder(self.disabled_db_check_box_d, self.target_db_check_box_d)
        dialog.setTabOrder(self.target_db_check_box_d, self.foreigners_db_check_box_d)
        dialog.setTabOrder(self.foreigners_db_check_box_d, self.deduct_paid_check_box)
        dialog.setTabOrder(self.deduct_paid_check_box, self.disabled_dp_check_box_d)
        dialog.setTabOrder(self.disabled_dp_check_box_d, self.target_dp_check_box_d)
        dialog.setTabOrder(self.target_dp_check_box_d, self.foreigners_dp_check_box_d)
        dialog.setTabOrder(self.foreigners_dp_check_box_d, self.continue_button_d)
        dialog.setTabOrder(self.continue_button_d, self.back_button_d)
        # Триггеры для пользовательского отчета
        self.loe_combo_box_d.currentIndexChanged.connect(self.set_combo_boxes)
        self.back_button_d.clicked.connect(self.close_window)
        self.continue_button_d.clicked.connect(self.get_condition)
        # Предварительная донастройка
        self.set_combo_boxes()

    def retranslate_ui(self, dialog):
        """Установка всех встроенных названий"""
        _translate = QtCore.QCoreApplication.translate
        dialog.setWindowTitle(_translate("Dialog", "StudInStudOut"))
        self.course_label_d.setText(_translate("Dialog", "Курс"))
        self.loe_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.loe_combo_box_d.setItemText(1, _translate("Dialog", "Бакалавриат"))
        self.loe_combo_box_d.setItemText(2, _translate("Dialog", "Магистратура"))
        self.loe_combo_box_d.setItemText(3, _translate("Dialog", "Специалитет"))
        self.loe_combo_box_d.setItemText(4, _translate("Dialog", "ККМТ"))
        self.loe_combo_box_d.setItemText(5, _translate("Dialog", "ТТД"))
        self.direction_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.direction_label_d.setText(_translate("Dialog", "Название направления подготовки"))
        self.foe_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.foe_combo_box_d.setItemText(1, _translate("Dialog", "Очная"))
        self.foe_combo_box_d.setItemText(2, _translate("Dialog", "Очно-заочная"))
        self.foe_combo_box_d.setItemText(3, _translate("Dialog", "Заочная"))
        self.course_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.course_combo_box_d.setItemText(1, _translate("Dialog", "1"))
        self.course_combo_box_d.setItemText(2, _translate("Dialog", "2"))
        self.course_combo_box_d.setItemText(3, _translate("Dialog", "3"))
        self.course_combo_box_d.setItemText(4, _translate("Dialog", "4"))
        self.course_combo_box_d.setItemText(5, _translate("Dialog", "5"))
        self.course_combo_box_d.setItemText(6, _translate("Dialog", "6"))
        self.loe_label_d.setText(_translate("Dialog", "Уровень обучения"))
        self.for_label_d.setText(_translate("Dialog", "Форма обучения"))
        self.year_label_d.setText(_translate("Dialog", "Год"))
        self.month_label_d.setText(_translate("Dialog", "Месяц"))
        self.year_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.month_combo_box_d.setItemText(0, _translate("Dialog", "Все"))
        self.month_combo_box_d.setItemText(1, _translate("Dialog", "Январь"))
        self.month_combo_box_d.setItemText(2, _translate("Dialog", "Февраль"))
        self.month_combo_box_d.setItemText(3, _translate("Dialog", "Март"))
        self.month_combo_box_d.setItemText(4, _translate("Dialog", "Апрель"))
        self.month_combo_box_d.setItemText(5, _translate("Dialog", "Май"))
        self.month_combo_box_d.setItemText(6, _translate("Dialog", "Июнь"))
        self.month_combo_box_d.setItemText(7, _translate("Dialog", "Июль"))
        self.month_combo_box_d.setItemText(8, _translate("Dialog", "Август"))
        self.month_combo_box_d.setItemText(9, _translate("Dialog", "Сентябрь"))
        self.month_combo_box_d.setItemText(10, _translate("Dialog", "Октябрь"))
        self.month_combo_box_d.setItemText(11, _translate("Dialog", "Ноябрь"))
        self.month_combo_box_d.setItemText(12, _translate("Dialog", "Декабрь"))
        self.enrollment_all_check_box_d.setText(_translate("Dialog", "Всего зачислено"))
        self.foreigners_eb_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (зачислено бюджет)"))
        self.foreigners_ea_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (всего зачислено)"))
        self.enrollment_paid_check_box_d.setText(_translate("Dialog",
                                                            "Зачислено по договорам об оказании платных "
                                                            "образовательных услуг"))
        self.target_ep_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(зачислено платное)"))
        self.disabled_ea_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды "
                                                        "(всего зачислено)"))
        self.foreigners_ep_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (зачислено платное)"))
        self.target_ea_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(всего зачислено)"))
        self.target_eb_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(зачислено бюджет)"))
        self.disabled_ep_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды "
                                                        "(зачислено платное)"))
        self.enrollment_budget_check_box_d.setText(_translate("Dialog",
                                                              "Зачислено за счет бюджетных ассигнований бюджета "
                                                              "субъекта РФ"))
        self.disabled_eb_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды "
                                                        "(зачислено бюджет)"))
        self.continue_button_d.setText(_translate("Dialog", "Продолжить"))
        self.foreigners_da_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (всего отчислено)"))
        self.deduct_budget_check_box_d.setText(_translate("Dialog",
                                                          "Отчислено за счет бюджетных ассигнований бюджета "
                                                          "субъекта РФ"))
        self.disabled_db_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды "
                                                        "(отчислено бюджет)"))
        self.target_db_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(отчислено бюджет)"))
        self.target_dp_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(отчислено платное)"))
        self.foreigners_dp_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (отчислено платное)"))
        self.target_da_check_box_d.setText(_translate("Dialog",
                                                      "Из них на места в рамках квоты целевого приема "
                                                      "(всего отчислено)"))
        self.disabled_dp_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды "
                                                        "(отчислено платное)"))
        self.disabled_da_check_box_d.setText(_translate("Dialog",
                                                        "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)"))
        self.deduct_paid_check_box.setText(_translate("Dialog",
                                                      "Отчислено по договорам об оказании платных "
                                                      "образовательных услуг"))
        self.deduct_all_check_box_d.setText(_translate("Dialog", "Всего отчислено"))
        self.foreigners_db_check_box_d.setText(_translate("Dialog", "Из них иностранные граждане (отчислено бюджет)"))
        self.back_button_d.setText(_translate("Dialog", "Назад"))

    def close_window(self):
        """Закрывает окно диалога"""
        self.dialog.close()

    def set_combo_boxes(self):
        """Устанавливает встроенные значения combo box"""
        self.direction_combo_box_d.blockSignals(True)
        self.direction_combo_box_d.clear()
        self.direction_combo_box_d.addItems(["Все", *self.get_directions(self.loe_combo_box_d.currentText())])
        self.direction_combo_box_d.blockSignals(False)
        self.year_combo_box_d.blockSignals(True)
        self.year_combo_box_d.clear()
        self.year_combo_box_d.addItems(["Все", *self.get_years(self.loe_combo_box_d.currentText())])
        self.year_combo_box_d.blockSignals(False)
        self.month_combo_box_d.blockSignals(True)
        self.month_combo_box_d.clear()
        self.month_combo_box_d.addItems(["Все", *self.get_months(self.loe_combo_box_d.currentText())])
        self.month_combo_box_d.blockSignals(False)

    def get_condition(self):
        """Получение данных необходимых для экспорта"""
        book_1 = {"Названия направления подготовки": [],
                  "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [], "Всего зачислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                  "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                  "Из них иностранные граждане (всего отчислено)": [],
                  "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                  "Из них иностранные граждане (зачислено бюджет)": [],
                  "Зачислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                  "Из них иностранные граждане (зачислено платное)": [],
                  "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                  "Из них иностранные граждане (отчислено бюджет)": [],
                  "Отчислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                  "Из них иностранные граждане (отчислено платное)": []}
        book_2 = {"Названия направления подготовки": [],
                  "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [], "Всего зачислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                  "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                  "Из них иностранные граждане (всего отчислено)": [],
                  "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                  "Из них иностранные граждане (зачислено бюджет)": [],
                  "Зачислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                  "Из них иностранные граждане (зачислено платное)": [],
                  "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                  "Из них иностранные граждане (отчислено бюджет)": [],
                  "Отчислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                  "Из них иностранные граждане (отчислено платное)": []}
        book_3 = {"Названия направления подготовки": [],
                  "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [], "Всего зачислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                  "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                  "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                  "Из них иностранные граждане (всего отчислено)": [],
                  "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                  "Из них иностранные граждане (зачислено бюджет)": [],
                  "Зачислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                  "Из них иностранные граждане (зачислено платное)": [],
                  "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                  "Из них иностранные граждане (отчислено бюджет)": [],
                  "Отчислено по договорам об оказании платных образовательных услуг": [],
                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                  "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                  "Из них иностранные граждане (отчислено платное)": []}
        is_needed = [True, True, True, True, True, self.enrollment_all_check_box_d.isChecked(),
                     self.disabled_ea_check_box_d.isChecked(), self.target_ea_check_box_d.isChecked(),
                     self.foreigners_ea_check_box_d.isChecked(), self.deduct_all_check_box_d.isChecked(),
                     self.disabled_da_check_box_d.isChecked(), self.target_da_check_box_d.isChecked(),
                     self.foreigners_da_check_box_d.isChecked(), self.enrollment_budget_check_box_d.isChecked(),
                     self.disabled_eb_check_box_d.isChecked(), self.target_eb_check_box_d.isChecked(),
                     self.foreigners_eb_check_box_d.isChecked(), self.enrollment_paid_check_box_d.isChecked(),
                     self.disabled_ep_check_box_d.isChecked(), self.target_ep_check_box_d.isChecked(),
                     self.foreigners_ep_check_box_d.isChecked(), self.deduct_budget_check_box_d.isChecked(),
                     self.disabled_db_check_box_d.isChecked(), self.target_db_check_box_d.isChecked(),
                     self.foreigners_db_check_box_d.isChecked(), self.deduct_paid_check_box.isChecked(),
                     self.disabled_dp_check_box_d.isChecked(), self.target_dp_check_box_d.isChecked(),
                     self.foreigners_dp_check_box_d.isChecked()]
        if self.foe_combo_box_d.currentText() == "Все":
            data = self.get_data(self.loe_combo_box_d.currentText(), "Очная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_1, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_1[chapter].append(recording[k])
            book_1 = {key: item for key, item in book_1.items() if item}
            data = self.get_data(self.loe_combo_box_d.currentText(), "Очно-заочная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_2, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_2[chapter].append(recording[k])
            book_2 = {key: item for key, item in book_2.items() if item}
            data = self.get_data(self.loe_combo_box_d.currentText(), "Заочная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_3, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_3[chapter].append(recording[k])
            book_3 = {key: item for key, item in book_3.items() if item}
            self.export_data(book_1, self.foe_combo_box_d.currentText(), book_2, book_3)
        elif self.foe_combo_box_d.currentText() == "Очная":
            data = self.get_data(self.loe_combo_box_d.currentText(), "Очная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_1, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_1[chapter].append(recording[k])
            book_1 = {key: item for key, item in book_1.items() if item}
            self.export_data(book_1, "Очная")
        elif self.foe_combo_box_d.currentText() == "Очно-заочная":
            data = self.get_data(self.loe_combo_box_d.currentText(), "Очно-заочная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_1, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_1[chapter].append(recording[k])
            book_1 = {key: item for key, item in book_1.items() if item}
            self.export_data(book_1, "Очно-заочная")
        elif self.foe_combo_box_d.currentText() == "Заочная":
            data = self.get_data(self.loe_combo_box_d.currentText(), "Заочная",
                                 self.direction_combo_box_d.currentText(), self.year_combo_box_d.currentText(),
                                 self.month_combo_box_d.currentText(), self.course_combo_box_d.currentText())
            for k, chapter in enumerate(book_1, 1):
                for recording in data:
                    if is_needed[k - 1]:
                        book_1[chapter].append(recording[k])
            book_1 = {key: item for key, item in book_1.items() if item}
            self.export_data(book_1, "Заочная")
