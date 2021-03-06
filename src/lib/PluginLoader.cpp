#include <omni/PluginLoader.h>

#include <omni/input/Interface.h>
#include <omni/mapping/Interface.h>
#include <omni/canvas/Interface.h>

#include <QCoreApplication>
#include <QDirIterator>
#include <QPluginLoader>
#include <QDebug>

namespace omni {
    PluginLoader::PluginLoader(
        std::vector<QDir> const& _paths,
        bool _defaultPaths) {
        load(_paths);
        if (_defaultPaths) {
            load(defaultPaths());
        }
    }

    void PluginLoader::load(QDir const& _path) {
        QDirIterator dirIt(_path);
        while (dirIt.hasNext()) {
            dirIt.next();
            auto _path = dirIt.filePath();
            if (!QFileInfo(_path).isFile()) continue;

            if (QFileInfo(_path).suffix() == "omnix") {
                loadPlugin(_path);
            }
        }
    }

    void PluginLoader::load(std::vector<QDir> const& _paths) {
        for (auto& _path : _paths) {
            qDebug() << "Plugin Path: " << _path.absolutePath();
            load(_path);
        }
    }

    void PluginLoader::loadPlugin(QString const& _path) {
        QPluginLoader _pluginLoader(_path);
        qDebug() << "Loading plugin: " << _path;
        QObject *plugin = _pluginLoader.instance();
        if (plugin) {
            auto* _inputInterface = qobject_cast<input::Interface*>(plugin);
            if (_inputInterface) {
                qDebug() << "Loaded input plugin: " << _inputInterface->getTypeId();
                _inputInterface->registerInFactory();
                return;
            }
            auto* _mappingInterface = qobject_cast<mapping::Interface*>(plugin);
            if (_mappingInterface) {
                qDebug() << "Loaded mapping plugin: " << _mappingInterface->getTypeId();
                _mappingInterface->registerInFactory();
                return;
            }
            auto* _canvasInterface = qobject_cast<canvas::Interface*>(plugin);
            if (_canvasInterface) {
                qDebug() << "Loaded canvas plugin: " << _canvasInterface->getTypeId();
                _canvasInterface->registerInFactory();
                return;
            }
        } else {
            qDebug() << "Error loading plugin: " << _pluginLoader.errorString();
        }
    }

    std::vector<QDir> PluginLoader::defaultPaths() {

        std::vector<QDir> _pluginDirs;
        _pluginDirs.push_back(QCoreApplication::applicationDirPath());
        #if defined(Q_OS_MAC)
        {
            QDir _appDir(QCoreApplication::applicationDirPath());
            if (_appDir.dirName() == "MacOS") {
                _appDir.cdUp();
                _appDir.cdUp();
                _appDir.cdUp();
                _pluginDirs.push_back(_appDir);
            }
        }
        #endif
        return _pluginDirs;
    }
}
