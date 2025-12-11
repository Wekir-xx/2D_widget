#ifndef WIDGET_SIGNALS_H
#define WIDGET_SIGNALS_H

#include <QObject>

///
/// \brief The WidgetSignals class - class for emit signals
///
class WidgetSignals : public QObject
{
    Q_OBJECT
public:

    // --- Main methods ---

    ///
    /// \brief triggerSignalTextValues - called in OpenGLWidget class, emit signal
    /// \param id - id of OpenGLWidget class
    ///
    void triggerSignalTextValues(int id)
    {
        emit updateTextValues(id);
    }

    ///
    /// \brief triggerSignalCurrentTab - called in MainWidget class, emit signal
    /// \param id - id of current tab
    ///
    void triggerSignalCurrentTab(int id)
    {
        emit updateCurrentTab(id);
    }

signals:

    ///
    /// \brief updateTextValues - signal, what MainWidget class accept
    /// \param id - id of OpenGLWidget class
    ///
    void updateTextValues(int id);

    ///
    /// \brief updateCurrentTab - signal, what external class accept
    /// \param id - id of current tab
    ///
    void updateCurrentTab(int id);
};

#endif // WIDGET_SIGNALS_H
