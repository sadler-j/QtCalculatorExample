#include "numberwidget.h"
#include "ui_numberwidget.h"

#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QSizePolicy"
#include "QToolButton"

#include "Controls/numberpad.h"
#include "Controls/operators.h"
#include "Controls/parenthesis.h"
#include "Controls/trigonometry.h"

NumberWidget::NumberWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberWidget)
{
    ui->setupUi(this);

    Controls::NumberPad* numberPad = new Controls::NumberPad;
    Controls::Operators* operators = new Controls::Operators;
    Controls::Parenthesis* parenthesis = new Controls::Parenthesis;
    Controls::Trigonometry* trigonometry = new Controls::Trigonometry;

    QFont font;
    font.setPointSize(20);

    QToolButton* clearButton = new QToolButton;
    clearButton->setText("C");
    clearButton->setFont(font);
    clearButton->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    clearButton->setShortcut(QKeySequence::Delete);

    QHBoxLayout* lowerLayout = new QHBoxLayout;
    lowerLayout->addWidget(numberPad);
    lowerLayout->addWidget(operators);
    lowerLayout->setStretchFactor(numberPad, 0);
    lowerLayout->setStretchFactor(operators, 0);

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(trigonometry);
    upperLayout->addWidget(parenthesis);
    upperLayout->addWidget(clearButton);
    upperLayout->setStretchFactor(trigonometry, 0);
    upperLayout->setStretchFactor(operators, 0);
    upperLayout->setStretchFactor(clearButton, 0);

    QVBoxLayout* primaryLayout = new QVBoxLayout;
    primaryLayout->addItem(upperLayout);
    primaryLayout->addItem(lowerLayout);
    primaryLayout->setStretchFactor(upperLayout, 0);
    primaryLayout->setStretchFactor(lowerLayout, 0);
    primaryLayout->setMargin(0);

    setLayout(primaryLayout);

    connect(numberPad, SIGNAL(ButtonPressed(std::string)),
            this, SLOT(ChildButtonPressed(std::string)));
    connect(operators, SIGNAL(ButtonPressed(std::string)),
            this, SLOT(ChildButtonPressed(std::string)));
    connect(trigonometry, SIGNAL(ButtonPressed(std::string)),
            this, SLOT(ChildButtonPressed(std::string)));
    connect(parenthesis, SIGNAL(ButtonPressed(std::string)),
            this, SLOT(ChildButtonPressed(std::string)));
    connect(clearButton, SIGNAL(clicked(bool)),
            this, SLOT(ClearPressed(bool)));
}

NumberWidget::~NumberWidget()
{
    delete ui;
}

void NumberWidget::ChildButtonPressed(const std::string &button)
{
    emit ButtonPressed(button);
}

void NumberWidget::ClearPressed(bool)
{
    emit Clear();
}
