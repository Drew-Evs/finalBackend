#pragma once

#include <QWidget>

class QComboBox;
class QLabel;
class QHBoxLayout;
class QVBoxLayout;
class QLineEdit;
class QTableWidget;
class QTableWidgetItem;


class PhysicalPage : public QWidget
{
public:
    //constructor
    PhysicalPage();

private:
    //methods to create/arrange the widgets on the page
    void createWidgets();
    void arrangeWidgets();
    void loadData();

    QComboBox* comboBox;
    QLabel* label;
    QLineEdit* lineEdit;
    QHBoxLayout* horiz_layout1;
    QHBoxLayout* horiz_layout2;
    QVBoxLayout* vertical_layout;
    QVBoxLayout* main_layout;
    QFont* title_font;
    QLabel* title_label;
    QTableWidget* table;
    QTableWidgetItem* item;
};
