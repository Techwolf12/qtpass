#ifndef TRAYICON_H_
#define TRAYICON_H_

#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QWidget>

/*!
    \class TrayIcon
    \brief Handles the systemtray icon and menu.
 */
class TrayIcon : public QWidget {
  Q_OBJECT

public:
  explicit TrayIcon(QMainWindow *parent);
  void showMessage(QString title, QString msg, int time);
  void setVisible(bool visible);

signals:

public slots:
  void showHideParent();
  void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
  void createActions();
  void createTrayIcon();

  QAction *showAction;
  QAction *hideAction;
  QAction *minimizeAction;
  QAction *maximizeAction;
  QAction *restoreAction;
  QAction *quitAction;

  QSystemTrayIcon *sysTrayIcon;
  QMenu *trayIconMenu;
  QMainWindow *parentwin;
};

#endif // TRAYICON_H_
