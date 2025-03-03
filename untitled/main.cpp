#include <QApplication>
#include <QTabBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QTabBar *tabBar = new QTabBar(&window);
    tabBar->addTab("Tab 1");
    tabBar->addTab("Tab 2");
    tabBar->addTab("Tab 3");
    layout->addWidget(tabBar);

    QLabel *label = new QLabel("Content of Tab 1", &window);
    layout->addWidget(label);

    QObject::connect(tabBar, &QTabBar::currentChanged, [&](int index){
        if (index == 0) {
            label->setText("Content of Tab 1");
        } else if (index == 1) {
            label->setText("Content of Tab 2");
        } else if (index == 2) {
            label->setText("Content of Tab 3");
        }
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
