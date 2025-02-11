#include <QCoreApplication>
#include <QSettings>



void info(QSettings &setting)
{
    qInfo() << "File:" << setting.fileName();
    qInfo() << "Keys:" << setting.allKeys();
}

void save(QSettings &setting)
{
    setting.setValue("test", 123);
    qInfo() << setting.status();
    qInfo() << "saved";
}

void load(QSettings &setting)
{
    qInfo() << setting.value("test").toString();
    bool ok;
    qInfo() << setting.value("test").toInt(&ok);
    if (!ok)
    {
        qInfo() << "Could not convert";
    }
}

void saveAge(QSettings *settings, QString group, QString name, int age)
{
    settings->beginGroup(group);
    settings->setValue(name, age);
    settings->endGroup();
}

int getAge(QSettings *settings, QString group, QString name)
{
    settings -> beginGroup(group);
    if (!settings -> contains(group))
    {
        qWarning() << " Does not contain name " << name << " in " << group;
        return 0;
    }

    bool ok;
    int value = settings -> value(name).toInt(&ok);

    settings->endGroup();

    if(!ok)
    {
        qWarning() << " Does not contain name " << name << " in " << group;

        return 0;
    }
    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    QCoreApplication::setOrganizationName("Org Name..");
    QCoreApplication::setOrganizationDomain("test.com");
    QCoreApplication::setApplicationName("App Name....");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    if (settings.allKeys().length() == 0)
    {
        qInfo() << "No settings found! Saving...";
        save(settings);
    }
    else
    {
        qInfo() << "loading settings";
        load(settings);
    }

    // groups

    saveAge(&settings, "People", "Bryan", 44);
    saveAge(&settings, "beer", "Adam", 33);
    saveAge(&settings, "beer", "Dan", 66);

    qInfo() << "Dan" << getAge(&settings, "beer", "Dan");
    qInfo() << "Bryan" << getAge(&settings, "People", "Bryan");
    qInfo() << "Bryan" << getAge(&settings, "beer", "Bryant");


    return a.exec();
}
