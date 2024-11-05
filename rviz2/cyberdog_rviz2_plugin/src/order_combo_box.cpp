#include "order_combo_box.h"

OrderComboBox::OrderComboBox(QWidget*): QHBoxLayout()
{
    order_list_ = new QComboBox();
    order_list_->addItem(" ");
    order_list_->addItem("STAND_UP");
    order_list_->addItem("PROSTRATE");
    order_list_->addItem("STEP_BACK");
    order_list_->addItem("TURN_AROUND");
    order_list_->addItem("HI_FIVE");
    order_list_->addItem("DANCE");
    order_list_->addItem("WELCOME");
    order_list_->addItem("TURN_OVER");
    order_list_->addItem("SIT");
    order_list_->addItem("SHOW");

    QLabel* order_label = new QLabel("⌘  Order: ");
    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp.setHorizontalStretch(1);
    order_label->setSizePolicy(sp);
    this->addWidget(order_label);

    order_list_->setSizePolicy(sp);
    this->addWidget(order_list_);

    order_button_ = new QPushButton("Execute");
    order_button_->setSizePolicy(sp);
    this->addWidget(order_button_);

    connect(order_list_ ,SIGNAL(currentIndexChanged(int)), SLOT(reemit_signal(int)));
    connect(order_button_, &QPushButton::clicked, [this](void) { Q_EMIT clicked(); });
}

OrderComboBox::~OrderComboBox(){}

void OrderComboBox::reemit_signal(int newvalue)
{
    int order_number = 0;
    switch(newvalue)
    {
        case(1):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_STAND_UP;
            break;
        case(2):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_PROSTRATE;
            break;
        case(3):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_STEP_BACK;
            break;
        case(4):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_TURN_AROUND;
            break;
        case(5):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_HI_FIVE;
            break;
        case(6):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_DANCE;
            break;
        case(7):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_WELCOME;
            break;
        case(8):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_TURN_OVER;
            break;
        case(9):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_SIT;
            break;
        case(10):
            order_number = motion_msgs::msg::MonOrder::MONO_ORDER_SHOW;
            break;
    }

    Q_EMIT valueChanged(order_number);
}
