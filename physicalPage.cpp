#include "physicalPage.hpp"
#include "sampleset.hpp"
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFont>
#include <QTableWidget>
#include <QTableWidgetItem>

PhysicalPage::PhysicalPage()
{
    createWidgets();  // Create the widgets
    loadData();
    arrangeWidgets(); // Arrange the widgets in the layout
    
}

void PhysicalPage::createWidgets()
{
    //new widgets
    title_label = new QLabel("Physical Pollutants");
    comboBox = new QComboBox(this);
    label = new QLabel("Pollutant", this);
    lineEdit = new QLineEdit("Location", this);
    table = new QTableWidget(this);

    //sets font/allignment
    title_font = new QFont("Arial",30);
    title_label->setFont(*title_font);

    //insert names
    comboBox->addItem("Litter");
    comboBox->addItem("Sewage");
    comboBox->addItem("Animal Faeces");
    comboBox->addItem("Metals");

    //links box/lavel
    connect(comboBox, &QComboBox::currentTextChanged, label, &QLabel::setText);
    label->setText("Pollutant");

    //set up table columns
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Name", "Compliancy", "Location", "Safe Level"});
    table->setRowCount(5);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //location filter
    lineEdit->setText("Location");
}

void PhysicalPage::arrangeWidgets()
{
    //new layouts
    main_layout = new QVBoxLayout(this);
    horiz_layout1 = new QHBoxLayout();
    horiz_layout2 = new QHBoxLayout();
    vertical_layout = new QVBoxLayout();

    //reduce space between vertical boxes
    vertical_layout->setSpacing(0);

    //stop stretching the boxes
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    
    //widgets to layouts
    vertical_layout->addWidget(comboBox);
    vertical_layout->addWidget(label);
    vertical_layout->addWidget(lineEdit);
    
    horiz_layout1->addLayout(vertical_layout);
    horiz_layout1->addWidget(table);

    main_layout->addWidget(title_label);
    main_layout->addLayout(horiz_layout1);

    setLayout(main_layout);
}

void PhysicalPage::loadData() {
    //reads to a sample set
    SampleSet data("../data/Y-2024-M.csv");
    std::vector<SampleSet> groups;
    groups.push_back(data.filterGroup(1));
    groups.push_back(data.filterGroup(2));
    groups.push_back(data.filterGroup(3));
    groups.push_back(data.filterGroup(4));

    table->setItem(0, 0, new QTableWidgetItem("Fluorates"));
    table->setItem(1, 0, new QTableWidgetItem("POPs"));
    table->setItem(2, 0, new QTableWidgetItem("Physical"));
    table->setItem(3, 0, new QTableWidgetItem("Common"));

    for (int row=0; row<groups.size(); row++){
        if(groups[row].deterSize()>0) {
            //prints the average with the units after it
            int avg = groups[row].getAvg();
            QString units = QString::fromStdString(groups[row].determinandAt(0).getUnits());
            QString avg_units = QString::number(avg) + " " + units;
            item = new QTableWidgetItem(avg_units);
            table->setItem(row,1,item);

            item = new QTableWidgetItem(QString::number(groups[row].determinandAt(0).getSafeLevel()));
            table->setItem(row,3,item);
        }
    }
}