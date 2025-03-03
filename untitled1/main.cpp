#include <QApplication>
#include <QTabBar>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QTabBar *tabBar = new QTabBar(&window);
    tabBar->addTab("Tab 1");
    tabBar->addTab("Tab 2");
    tabBar->addTab("Tab 3");
    tabBar->setMovable(true); // Enable tab moving

    layout->addWidget(tabBar);
    window.setLayout(layout);
    window.show();

    return app.exec();
}
