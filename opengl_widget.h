#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include "widget_signals.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QRgb>

#include <unordered_map>
#include <algorithm>

#define MIN_ZOOM 0.5 ///< Minimum zoom
#define ZOOM_FACTOR_GRID 2 ///< At what increase or decrease in zoom grid changes
#define START_ZOOM 1 ///< Initial zoom in initialization
#define ZOOM_COEFFICIENT 0.05 ///< Coefficient of change of zoom
#define DEFAULT_STEP_GRID 10 ///<
#define MAX_ZOOM 100 ///<

///
/// \brief The TYPE_VISIBLE enum - type of data that OpenGL will display
///
enum class TYPE_VISIBLE : int {
    SHORT = 0,
    INT,
    FLOAT,
    DOUBLE
};

///
/// \brief The OpenGLWidget class - class responsible for rendering
///
template<typename type, TYPE_VISIBLE T>
class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:

    // --- Helper structs ---

    ///
    /// \brief The GRAPH_MODE enum - modes in which graph will display
    ///
    enum class GRAPH_MODE : int {
        UNDEFINED = -1,
        LINE,
        COLUMN,
        RECTANGLE
    };

    ///
    /// \brief The SCENE_MODE enum - modes in which scene will change
    ///
    enum class SCENE_MODE : int {
        UNDEFINED = -1,
        HORIZONTAL,
        BOTH,
        VERTICAL
    };

    ///
    /// \brief The GraphData class - store elements of graph
    ///
    struct GraphData {
        std::vector<type> graph; ///< array of graph values
        type      startPoint{0}; ///< starting point of graph
        QRgb           color{0}; ///< graph color
        bool         show{true}; ///< show or unshow graph

        // --- Constructors/destructors ---

        GraphData() = default;
        GraphData(std::vector<type> &graph, QRgb color)
            : graph{graph}, color{color}
        {}
        ~GraphData() = default;
    };

    // --- Constructors/destructors ---

    OpenGLWidget(int id, QWidget *parent = nullptr);
    ~OpenGLWidget() = default;

    // --- Main methods ---

    ///
    /// \brief addGraph - add graph to scene
    /// \param idGraph - id of graph
    /// \param graph - all data on graph
    ///
    void addGraph(int idGraph, GraphData &graph);

    ///
    /// \brief setValuesGraph - set array of graph values
    /// \param idGraph - id of graph
    /// \param graph - array of graph values
    ///
    void setValuesGraph(int idGraph, const std::vector<type> &graph);

    ///
    /// \brief deleteGraph - delete graph from scene
    /// \param idGraph - id of graph
    ///
    void deleteGraph(int idGraph);

    ///
    /// \brief existsGraph - whether graph exists
    /// \param idGraph - id of graph
    /// \return
    ///
    bool existsGraph(int idGraph);

    ///
    /// \brief updateScene - update scene
    ///
    void updateScene();

    ///
    /// \brief swapMouseButton - swap mouse button
    ///
    void swapMouseButton();

    // --- Setters ---

    ///
    /// \brief setAutoUpdateScene - set update scene auto
    /// \param set - whether to update scene auto
    ///
    void setUpdateSceneAuto(bool set);

    ///
    /// \brief setSignal - set object class Signals
    /// \param signal - object class Signals
    ///
    void setSignal(WidgetSignals *signal);

    ///
    /// \brief setStartPointGraph - set point of beginning of graph
    /// \param idGraph - id of graph
    /// \param startPoint - point of beginning of graph
    ///
    void setStartPointGraph(int idGraph, double startPoint);

    ///
    /// \brief setStepGraph - set distance between each value on graphs
    /// \param step - distance between each value on graph
    ///
    void setStepGraph(double step);

    ///
    /// \brief setStepGrid - set distance between each part of the grid, XY
    /// \param step - distance between each part of the grid, XY
    ///
    void setStepGrid(std::pair<double, double> step);

    ///
    /// \brief setMinMaxXYScene - set minimum and maximum X for scene
    /// \param minX - minimum for X axis
    /// \param minX - maximum for X axis
    ///
    void setMinMaxXScene(double minX, double maxX);

    ///
    /// \brief setMinMaxXYScene - set minimum and maximum Y for scene
    /// \param minY - minimum for Y axis
    /// \param minY - maximum for Y axis
    ///
    void setMinMaxYScene(double minY, double maxY);

    ///
    /// \brief setGraphMode - set mode in which graph will display
    /// \param mode - mode in which graph will display
    ///
    void setGraphMode(GRAPH_MODE mode);

    ///
    /// \brief setSceneMode - set mode in which scene will change
    /// \param mode - mode in which scene will change
    ///
    void setSceneMode(SCENE_MODE mode);

    ///
    /// \brief setResetSceneButton - set button which will reset scene
    /// \param button - button which will reset scene
    ///
    void setResetSceneButton(Qt::Key button);

    ///
    /// \brief setCancelSelectButton - set button which will cancel selected scene
    /// \param button - button which will cancel selected scene
    ///
    void setCancelSelectButton(Qt::Key button);

    ///
    /// \brief swapVHButtons - swap buttons which will change scene in vertical and horizontal space
    ///
    void swapVHButtons();

    ///
    /// \brief setGraphVisible - whether to show graph
    /// \param idGraph - id of graph
    /// \param show - whether to show item
    ///
    void setGraphVisible(int idGraph, bool show);

    ///
    /// \brief setGridVisible - whether to show grid
    /// \param show - whether to show item
    ///
    void setGridVisible(bool show);

    ///
    /// \brief setGridCursorVisible - whether to show cursor grid
    /// \param show - whether to show item
    ///
    void setGridCursorVisible(bool show);

    ///
    /// \brief setColorGraph - set graph color
    /// \param idGraph - id of graph
    /// \param color - item color

    void setColorGraph(int idGraph, QRgb color);

    ///
    /// \brief setColorBack - set background color
    /// \param color - item color
    ///
    void setColorBack(QRgb color);

    ///
    /// \brief setColorGrid - set grid color
    /// \param color - item color
    ///
    void setColorGrid(QRgb color);

    ///
    /// \brief setColorGridCursor - set cursor grid color
    /// \param color - item color
    ///
    void setColorGridCursor(QRgb color);

    ///
    /// \brief setColorAxes - set axes color
    /// \param color - item color
    ///
    void setColorAxes(QRgb color);

    ///
    /// \brief setWidthGraph - set line width graph
    /// \param width - line width
    ///
    void setWidthGraph(float width);

    ///
    /// \brief setWidthGrid - set line width grid
    /// \param width - line width
    ///
    void setWidthGrid(float width);

    ///
    /// \brief setWidthGridCursor - set line width grid cursor
    /// \param width - line width
    ///
    void setWidthGridCursor(float width);

    ///
    /// \brief setWidthAxes - set line width axes
    /// \param width - line width
    ///
    void setWidthAxes(float width);

    // --- Getters ---

    ///
    /// \brief getGridValues - obtaining location of each line of grid in pixels
    /// \return - pair of arrays, first for X axis, second for Y axis
    ///
    std::pair<std::vector<int>&, std::vector<int>&> getGridValues();

    ///
    /// \brief getValues - obtaining values of each line of grid
    /// \return - pair of arrays, first for X axis, second for Y axis
    ///
    std::pair<std::vector<double>&, std::vector<double>&> getValues();

private:

    // --- Event methods ---

    bool eventFilter(QObject *obj, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    // --- OpenGL methods ---

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    // --- Helper methods ---

    ///
    /// \brief coordWDtoGL - conversion coordinates from Widget plane to GL
    /// \param point - point in coordinate system of widget
    /// \return - point in coordinate system of OpenGL
    ///
    QPointF coordWDtoGL(QPoint point);

    ///
    /// \brief coordGLtoWD - conversion coordinates from GL plane to Widget
    /// \param point - point in coordinate system of OpenGL
    /// \return - point in coordinate system of widget
    ///
    QPoint coordGLtoWD(QPointF point);

    ///
    /// \brief resetScene - dropping zoom and indentation
    ///
    void resetScene();

    ///
    /// \brief updateMouseMove - data updating when mouse movement or change of mouse movement mode
    ///
    void updateMouseMove();

    ///
    /// \brief updateBorder - сhecking border of scene
    ///
    void updateBorder();

    ///
    /// \brief updateGrid - update grid, grid values
    /// \param updateFullGrid - whether to update full grid
    ///
    void updateGrid(bool updateFullGrid);

    ///
    /// \brief updateGL - update GL border
    ///
    void updateGLBorder();

private:

    // --- Helper structs ---

    ///
    /// \brief The MOUSE_MOVE_MODE enum - mouse movement mode
    ///
    enum class MOUSE_MOVE_MODE : int {
        UNDEFINED = -1,
        START, ///< Mouse press left button
        ZOOM,
        RESET
    };

    // --- Fields ---

    int                                    m_id; ///< External widget id
    bool                                 m_init; ///<
    bool                      m_updateSceneAuto; ///<

    WidgetSignals                     *m_signal; ///< Object class Signals

    std::unordered_map<int, GraphData> m_graphs; ///< Data for each graph

    std::pair<double, double>      m_zoomFactor; ///< Current scene zoom factor X, Y = first, second
    std::pair<double, double>  m_lastZoomFactor; ///< Previous scene zoom factor X, Y = first, second
    std::pair<double, double>          m_offset; ///< Current shift along axes X, Y = first, second

    std::pair<int, int>                m_WDSize; ///< Current Widget size X, Y = first, second
    std::pair<double, double>    m_pixelDencity; ///< Pixel density along axes  X, Y = first, second
    std::pair<double, double>       m_pixelSize; ///< Pixel sizes in scene measure
    std::pair<double, double>       m_sceneSize; ///< Scene size X, Y = first, second

    std::pair<double, double>         m_MinMaxX; ///< Minimum and maximum values of X
    std::pair<type, type>             m_MinMaxY; ///< Minimum and maximum values of Y
    QPointF                       m_borderMaxGL; ///< Max scene border, right upper corner
    QPointF                       m_borderMinGL; ///< Max scene border, left lower corner

    QPoint                     m_lastMousePosWD; ///< Previous cursor position in widget plane
    QPoint                     m_currMousePosWD; ///< Current cursor position in widget plane
    QPointF                    m_lastMousePosGL; ///< Previous cursor position in GL plane
    QPointF                    m_currMousePosGL; ///< Current cursor position in GL plane

    QPointF                m_selectedSceneBegin; ///< Start point of discharge
    QPointF                  m_selectedSceneEnd; ///< End point of discharge
    QPointF                 m_saveSelectedBegin; ///< Point when pressing left mouse button

    std::vector<float>        m_gridHorizontalY; ///< Coord of horizontal grid
    std::vector<float>          m_gridVerticalX; ///< Coord of vertical grid

    std::vector<int>          m_textHorizontalY; ///< Coord of values for horizontal grid
    std::vector<int>            m_textVerticalX; ///< Coord of values for vertical grid
    std::vector<double>        m_valueHorizontalY; ///< Values for horizontal grid
    std::vector<double>          m_valueVerticalX; ///< Values for vertical grid

    type                            m_stepGraph; ///< Distance between each value on graph
    std::pair<double, double>        m_stepGrid; ///< Distance between each part of the grid, XY
    std::pair<double, double>  m_staticStepGrid; ///< Static distance between each part of the grid, XY
    bool                             m_showGrid; ///< Whether grid is shown
    bool                       m_showGridCursor; ///< Whether cursor grid is shown

    std::pair<QPointF, QPointF>          m_axes; ///< Pair point in coordinate system OpenGL, left lower corner,
    ///< right upper corner

    QRgb                            m_colorBack; ///< Background color
    QRgb                            m_colorGrid; ///< Grid color
    QRgb                      m_colorGridCursor; ///< Cursor grid color
    QRgb                            m_colorAxes; ///< Axes color

    float                          m_widthGraph; ///< Graph line width
    float                           m_widthGrid; ///< Grid line width
    float                     m_widthGridCursor; ///< Cursor grid line width
    float                           m_widthAxes; ///< Axes line width

    GRAPH_MODE                      m_graphMode; ///< Mode in which graph will display
    SCENE_MODE                      m_sceneMode; ///< Mode in which scene will change
    SCENE_MODE                m_staticSceneMode; ///< Mode in which scene will change by default
    MOUSE_MOVE_MODE             m_mouseMoveMode; ///< Mouse movement mode
    Qt::MouseButton                m_moveButton; ///<
    Qt::MouseButton                m_zoomButton; ///<
    Qt::Key                  m_resetSceneButton; ///<
    Qt::Key                m_cancelSelectButton; ///<
    Qt::Key                    m_verticalButton; ///<
    Qt::Key                  m_horizontalButton; ///<
    Qt::KeyboardModifier     m_verticalModifier; ///<
    Qt::KeyboardModifier   m_horizontalModifier; ///<
};

template<typename type, TYPE_VISIBLE T>
OpenGLWidget<type, T>::OpenGLWidget(int id, QWidget *parent)
    : QOpenGLWidget(parent), m_id{id}
{
    // Event filter instalation
    this->installEventFilter(this);

    setMouseTracking(true);

    // Border
    m_MinMaxX = {0, 1};
    m_MinMaxY = {0, 1};

    m_lastZoomFactor = {1, 1};
    m_stepGraph = 1;
    m_stepGrid = {1, 1};
    m_staticStepGrid = {0, 0};

    m_init = false;
    m_updateSceneAuto = true;
    m_showGrid = true;
    m_showGridCursor = true;

    m_colorBack = qRgb(255, 255, 255);
    m_colorGrid = qRgb(175, 175, 175);
    m_colorGridCursor = qRgba(50, 50, 50, 200);

    m_widthGraph = m_widthGrid = m_widthGridCursor = m_widthAxes = 1;

    m_graphMode = GRAPH_MODE::LINE;
    m_sceneMode = SCENE_MODE::BOTH;
    m_staticSceneMode = SCENE_MODE::BOTH;
    m_mouseMoveMode = MOUSE_MOVE_MODE::UNDEFINED;
    m_moveButton = Qt::MouseButton::RightButton;
    m_zoomButton = Qt::MouseButton::LeftButton;
    m_resetSceneButton = Qt::Key::Key_Space;
    m_cancelSelectButton = Qt::Key::Key_Escape;
    m_verticalButton = Qt::Key::Key_Shift;
    m_horizontalButton = Qt::Key::Key_Control;
    m_verticalModifier = Qt::KeyboardModifier::ShiftModifier;
    m_horizontalModifier = Qt::KeyboardModifier::ControlModifier;

    m_graphs.reserve(10);

    resetScene();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::addGraph(int idGraph, GraphData &graph)
{
    m_graphs[idGraph] = graph;
    if (m_updateSceneAuto)
        resetScene();
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setValuesGraph(int idGraph, const std::vector<type> &graph)
{
    m_graphs[idGraph].graph = graph;
    if (m_updateSceneAuto)
        resetScene();
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::deleteGraph(int idGraph)
{
    m_graphs.erase(idGraph);
    if (m_updateSceneAuto)
        resetScene();
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setGraphVisible(int idGraph, bool show)
{
    m_graphs[idGraph].show = show;
    update();
}

template<typename type, TYPE_VISIBLE T>
bool OpenGLWidget<type, T>::existsGraph(int idGraph)
{
    return m_graphs.find(idGraph) != m_graphs.end();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::updateScene()
{
    resetScene();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::swapMouseButton()
{
    std::swap(m_moveButton, m_zoomButton);
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setGridVisible(bool show)
{
    m_showGrid = show;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setGridCursorVisible(bool show)
{
    m_showGridCursor = show;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setUpdateSceneAuto(bool set)
{
    m_updateSceneAuto = set;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setSignal(WidgetSignals *signal)
{
    m_signal = signal;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setStartPointGraph(int idGraph, double startPoint)
{
    m_graphs[idGraph].startPoint = startPoint;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setStepGraph(double step)
{
    m_sceneSize.first = m_sceneSize.first / m_stepGraph * step;
    m_stepGraph = step;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setStepGrid(std::pair<double, double> step)
{
    m_staticStepGrid = step;
    if (step.first > 0)
        m_stepGrid.first = step.first;
    if (step.second > 0)
        m_stepGrid.second = step.second;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setMinMaxXScene(double minX, double maxX)
{
    m_MinMaxX = {minX, maxX};
    m_zoomFactor.first = 1;
    m_lastZoomFactor.first = 1;
    m_offset.first = 0;

    m_sceneSize.first = m_MinMaxX.second - m_MinMaxX.first;

    if (m_staticStepGrid.first <= 0)
        m_stepGrid.first = m_sceneSize.first / DEFAULT_STEP_GRID;

    updateGLBorder();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setMinMaxYScene(double minY, double maxY)
{
    m_MinMaxY = {minY, maxY};
    m_zoomFactor.second = 1;
    m_lastZoomFactor.second = 1;
    m_offset.second = 0;

    m_sceneSize.second = m_MinMaxY.second - m_MinMaxY.first;

    if (m_staticStepGrid.second <= 0)
        m_stepGrid.second = m_sceneSize.second / DEFAULT_STEP_GRID;

    updateGLBorder();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setGraphMode(GRAPH_MODE mode)
{
    m_graphMode = mode;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setSceneMode(SCENE_MODE mode)
{
    m_staticSceneMode = mode;
    m_sceneMode = mode;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setResetSceneButton(Qt::Key button)
{
    m_resetSceneButton = button;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setCancelSelectButton(Qt::Key button)
{
    m_cancelSelectButton = button;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::swapVHButtons()
{
    std::swap(m_verticalButton, m_horizontalButton);
    std::swap(m_verticalModifier, m_horizontalModifier);
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setColorGraph(int idGraph, QRgb color)
{
    m_graphs[idGraph].color = color;
    update();
}


template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setColorBack(QRgb color)
{
    m_colorBack = color;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setColorGrid(QRgb color)
{
    m_colorGrid = color;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setColorGridCursor(QRgb color)
{
    m_colorGridCursor = color;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setColorAxes(QRgb color)
{
    m_colorAxes = color;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setWidthGraph(float width)
{
    m_widthGraph = width;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setWidthGrid(float width)
{
    m_widthGrid = width;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setWidthGridCursor(float width)
{
    m_widthGridCursor = width;
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::setWidthAxes(float width)
{
    m_widthAxes = width;
    update();
}

template<typename type, TYPE_VISIBLE T>
std::pair<std::vector<int> &, std::vector<int> &> OpenGLWidget<type, T>::getGridValues()
{
    return {m_textVerticalX, m_textHorizontalY};
}

template<typename type, TYPE_VISIBLE T>
std::pair<std::vector<double> &, std::vector<double> &> OpenGLWidget<type, T>::getValues()
{
    return {m_valueVerticalX, m_valueHorizontalY};
}

template<typename type, TYPE_VISIBLE T>
bool OpenGLWidget<type, T>::eventFilter(QObject *obj, QEvent *event)
{
    QEvent::Type Type = event->type();

    // Leave/Enter mouse cursor at widget area
    if (Type == QEvent::Enter) {
        this->setFocus();
    }

    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    // Zoom mode selection with KeyPress (SHIFT - VERTICAL, CTRL - HORIZONTAL)
    if (obj == this && Type == QEvent::KeyPress) {
        if (keyEvent->key() == m_verticalButton) {
            if (keyEvent->modifiers() & m_horizontalModifier)
                m_sceneMode = SCENE_MODE::BOTH;
            else
                m_sceneMode = SCENE_MODE::VERTICAL;

            if (m_mouseMoveMode == MOUSE_MOVE_MODE::RESET || m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
                m_selectedSceneBegin = m_saveSelectedBegin;
                updateMouseMove();
            }
        } else if (keyEvent->key() == m_horizontalButton) {
            if (keyEvent->modifiers() & m_verticalModifier)
                m_sceneMode = SCENE_MODE::BOTH;
            else
                m_sceneMode = SCENE_MODE::HORIZONTAL;

            if (m_mouseMoveMode == MOUSE_MOVE_MODE::RESET || m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
                m_selectedSceneBegin = m_saveSelectedBegin;
                updateMouseMove();
            }
        } else if (keyEvent->key() == m_resetSceneButton) {
            m_mouseMoveMode = MOUSE_MOVE_MODE::UNDEFINED;
            resetScene();
        } else if (keyEvent->key() == m_cancelSelectButton) {
            m_mouseMoveMode = MOUSE_MOVE_MODE::UNDEFINED;
        }
    }

    // Zoom mode reset with KeyRelease (BOTH)
    if (obj == this && Type == QEvent::KeyRelease) {
        if (keyEvent->key() == m_horizontalButton || keyEvent->key() == m_verticalButton) {
            if (keyEvent->modifiers() & m_verticalModifier)
                m_sceneMode = SCENE_MODE::VERTICAL;
            else if (keyEvent->modifiers() & m_horizontalModifier)
                m_sceneMode = SCENE_MODE::HORIZONTAL;
            else
                m_sceneMode = m_staticSceneMode;

            if (m_mouseMoveMode == MOUSE_MOVE_MODE::RESET || m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
                m_selectedSceneBegin = m_saveSelectedBegin;
                updateMouseMove();
            }
        }
    }

    update();

    return QWidget::eventFilter(this, event);
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == m_moveButton) {
        m_currMousePosWD = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    if (event->button() == m_zoomButton) {
        m_mouseMoveMode = MOUSE_MOVE_MODE::START;
        m_saveSelectedBegin = m_selectedSceneEnd = m_selectedSceneBegin = coordWDtoGL(event->pos());
    }
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == m_moveButton) {
        unsetCursor();
    } else if (event->button() == m_zoomButton) {
        if (m_mouseMoveMode == MOUSE_MOVE_MODE::RESET) {
            resetScene();
        } else if (m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
            if (m_sceneMode <= SCENE_MODE::BOTH &&
                    (abs(m_sceneSize.first) / abs(m_selectedSceneEnd.x() - m_selectedSceneBegin.x()))
                    < m_zoomFactor.first * MAX_ZOOM) {
                m_zoomFactor.first = abs(m_sceneSize.first) / abs(m_selectedSceneEnd.x() - m_selectedSceneBegin.x());
                m_offset.first += (coordWDtoGL(QPoint{0, 0}).x() - m_selectedSceneBegin.x()) * m_zoomFactor.first;
            }
            if (m_sceneMode >= SCENE_MODE::BOTH &&
                    (abs(m_sceneSize.second) / abs(m_selectedSceneEnd.y() - m_selectedSceneBegin.y()))
                    < m_zoomFactor.first * MAX_ZOOM)  {
                m_zoomFactor.second = abs(m_sceneSize.second) / abs(m_selectedSceneEnd.y() - m_selectedSceneBegin.y());
                m_offset.second += (coordWDtoGL(QPoint{0, m_WDSize.second / 2}).y()
                                    - (m_selectedSceneEnd.y() + m_selectedSceneBegin.y()) / 2) * m_zoomFactor.second;
            }

            updateGrid(false);
            update();
        }
        m_mouseMoveMode = MOUSE_MOVE_MODE::UNDEFINED;
    }
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::mouseMoveEvent(QMouseEvent *event)
{
    m_lastMousePosWD = m_currMousePosWD;
    m_currMousePosWD = event->pos();
    m_lastMousePosGL = coordWDtoGL(m_lastMousePosWD);
    m_currMousePosGL = coordWDtoGL(m_currMousePosWD);

    if (event->buttons() & m_moveButton) {
        if (m_sceneMode <= SCENE_MODE::BOTH)
            m_offset.first += (m_currMousePosGL.x() - m_lastMousePosGL.x()) * m_zoomFactor.first;
        if (m_sceneMode >= SCENE_MODE::BOTH)
            m_offset.second += (m_currMousePosGL.y() - m_lastMousePosGL.y()) * m_zoomFactor.second;

        updateBorder();
    } else if (event->buttons() & m_zoomButton && m_mouseMoveMode != MOUSE_MOVE_MODE::UNDEFINED) {
        updateMouseMove();
    }

    updateGrid(false);
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::wheelEvent(QWheelEvent *event)
{
    float delta = event->angleDelta().y() > 0 ? START_ZOOM + ZOOM_COEFFICIENT : START_ZOOM - ZOOM_COEFFICIENT;

    QPoint cursor = mapFromGlobal(this->cursor().pos());
    m_currMousePosWD = {cursor.x(), cursor.y()};
    m_lastMousePosGL = coordWDtoGL(m_currMousePosWD);

    if (m_sceneMode <= SCENE_MODE::BOTH) {
        m_zoomFactor.first *= delta;
        if (m_zoomFactor.first < MIN_ZOOM)
            m_zoomFactor.first = MIN_ZOOM;
        m_currMousePosGL = coordWDtoGL(m_currMousePosWD);
        m_offset.first += (m_currMousePosGL.x() - m_lastMousePosGL.x())
                          + (m_currMousePosGL.x() - m_lastMousePosGL.x()) * (m_zoomFactor.first - 1);
    }
    if (m_sceneMode >= SCENE_MODE::BOTH) {
        m_zoomFactor.second *= delta;
        if (m_zoomFactor.second < MIN_ZOOM)
            m_zoomFactor.second = MIN_ZOOM;
        m_currMousePosGL = coordWDtoGL(m_currMousePosWD);
        m_offset.second += (m_currMousePosGL.y() - m_lastMousePosGL.y())
                           + (m_currMousePosGL.y() - m_lastMousePosGL.y()) * (m_zoomFactor.second - 1);
    }

    updateBorder();
    updateGrid(false);
    update();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::initializeGL()
{
    initializeOpenGLFunctions();

    glShadeModel(GL_SMOOTH); // Разрешить плавное цветовое сглаживание
    glClearColor(qRed(m_colorBack), qGreen(m_colorBack), qBlue(m_colorBack), 1.0f); // Обновление цвета
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Улучшение в вычислении перспективы

    m_init = true;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::resizeGL(int w, int h)
{
    // Widget size
    m_WDSize.first = w;
    m_WDSize.second = h;
    // Pixel density
    m_pixelDencity.first = (float)m_WDSize.first / m_sceneSize.first;
    m_pixelDencity.second = (float)m_WDSize.second / m_sceneSize.second;
    // Pixel size
    m_pixelSize.first = m_sceneSize.first / (float)m_WDSize.first / m_zoomFactor.first;
    m_pixelSize.second = m_sceneSize.second / (float)m_WDSize.second / m_zoomFactor.second;
    //Border
    m_borderMaxGL = coordWDtoGL(QPoint{m_WDSize.first * 3 / 2, -m_WDSize.second / 2});
    m_borderMinGL = coordWDtoGL(QPoint{-m_WDSize.first / 2, m_WDSize.second * 3 / 2});

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(m_MinMaxX.first,
            m_MinMaxX.second,
            m_MinMaxY.first,
            m_MinMaxY.second,
            1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(m_offset.first, m_offset.second, 0.0);
    glScalef(m_zoomFactor.first, m_zoomFactor.second, 1.0);

    if (m_showGridCursor) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x3333);
        glLineWidth(m_widthGridCursor);
        glBegin(GL_LINES);
        {
            glColor4ub(qRed(m_colorGridCursor), qGreen(m_colorGridCursor), qBlue(m_colorGridCursor), qAlpha(m_colorGridCursor));
            glVertex2d(m_axes.first.x(), m_currMousePosGL.y());
            glVertex2d(m_axes.second.x(), m_currMousePosGL.y());
            glVertex2d(m_currMousePosGL.x(), m_axes.first.y());
            glVertex2d(m_currMousePosGL.x(), m_axes.second.y());
        }
        glEnd();
        glDisable(GL_LINE_STIPPLE);
    }

    if (m_showGrid) {
        // Vertical grid
        glLineWidth(m_widthGrid);
        glBegin(GL_LINES);
        glColor4ub(qRed(m_colorGrid), qGreen(m_colorGrid), qBlue(m_colorGrid), qAlpha(m_colorGrid));
        for (size_t i = 0; i < m_gridVerticalX.size(); i++) {
            glVertex2d(m_gridVerticalX[i], m_borderMaxGL.y());
            glVertex2d(m_gridVerticalX[i], m_borderMinGL.y());
        }
        // Horizontal grid
        for (size_t i = 0; i < m_gridHorizontalY.size(); i++) {
            glVertex2d(m_borderMaxGL.x(), m_gridHorizontalY[i]);
            glVertex2d(m_borderMinGL.x(), m_gridHorizontalY[i]);
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnd();
    }

    glLineWidth(m_widthGraph);
    for (const auto &graph : m_graphs) {
        const auto &data = graph.second;
        if (data.show == false)
            continue;

        glColor4ub(qRed(data.color), qGreen(data.color), qBlue(data.color), qAlpha(data.color));
        glBegin(GL_LINE_STRIP);
        {
            if (m_graphMode == GRAPH_MODE::LINE) {
                type start = data.startPoint;
                if constexpr(T == TYPE_VISIBLE::SHORT) {
                    for (size_t i = 0; i < data.graph.size(); ++i, start += m_stepGraph) {
                        glVertex2s(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::INT) {
                    for (size_t i = 0; i < data.graph.size(); ++i, start += m_stepGraph) {
                        glVertex2i(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::FLOAT) {
                    for (size_t i = 0; i < data.graph.size(); ++i, start += m_stepGraph) {
                        glVertex2f(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::DOUBLE) {
                    for (size_t i = 0; i < data.graph.size(); ++i, start += m_stepGraph) {
                        glVertex2d(start, data.graph[i]);
                    }
                }
            } else if (m_graphMode == GRAPH_MODE::COLUMN) {
                type start = data.startPoint;
                if constexpr(T == TYPE_VISIBLE::SHORT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2s(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2s(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::INT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2i(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2i(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::FLOAT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2f(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2f(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::DOUBLE) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2d(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2d(start, data.graph[i]);
                    }
                }
            } else if (m_graphMode == GRAPH_MODE::RECTANGLE) {
                type start = data.startPoint - m_stepGraph / 2;
                if constexpr(T == TYPE_VISIBLE::SHORT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2s(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2s(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::INT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2i(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2i(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::FLOAT) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2f(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2f(start, data.graph[i]);
                    }
                } else if constexpr(T == TYPE_VISIBLE::DOUBLE) {
                    for (size_t i = 0; i < data.graph.size(); ++i) {
                        glVertex2d(start, data.graph[i]);
                        start += m_stepGraph;
                        glVertex2d(start, data.graph[i]);
                    }
                }
            }
        }
        glEnd();
    }

    if (m_mouseMoveMode != MOUSE_MOVE_MODE::UNDEFINED) {
        glColor4ub(128, 128, 128, 255);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
        {
            glEnable(GL_LINE_STIPPLE);
            glLineStipple(1, 0x3333);
            if (m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
                // Selection rectangle
                glVertex2d(m_selectedSceneBegin.x(), m_selectedSceneBegin.y());
                glVertex2d(m_selectedSceneBegin.x(), m_selectedSceneEnd.y());
                glVertex2d(m_selectedSceneEnd.x(), m_selectedSceneEnd.y());
                glVertex2d(m_selectedSceneEnd.x(), m_selectedSceneBegin.y());
            } else if (m_mouseMoveMode == MOUSE_MOVE_MODE::RESET) {
                // Reset line
                glVertex2d(m_selectedSceneBegin.x(), m_selectedSceneBegin.y());
                glVertex2d(m_selectedSceneEnd.x(), m_selectedSceneEnd.y());
            }
            glDisable(GL_LINE_STIPPLE);
        }
        glEnd();

        // Selection rectangle
        if (m_mouseMoveMode == MOUSE_MOVE_MODE::ZOOM) {
            glColor4ub(173, 216, 230, 100);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glBegin(GL_QUADS);
            {
                glVertex2d(m_selectedSceneBegin.x(), m_selectedSceneBegin.y());
                glVertex2d(m_selectedSceneBegin.x(), m_selectedSceneEnd.y());
                glVertex2d(m_selectedSceneEnd.x(), m_selectedSceneEnd.y());
                glVertex2d(m_selectedSceneEnd.x(), m_selectedSceneBegin.y());
            }
            glEnd();
        }
    }

    glLineWidth(m_widthAxes);
    glColor4ub(qRed(m_colorAxes), qGreen(m_colorAxes), qBlue(m_colorAxes), qAlpha(m_colorAxes));
    glBegin(GL_LINES);
    {
        //axis Y
        glVertex2d(m_axes.first.x(), m_axes.first.y());
        glVertex2d(m_axes.first.x(), m_axes.second.y());
        //axis X
        glVertex2d(m_axes.first.x(), m_axes.second.y());
        glVertex2d(m_axes.second.x(), m_axes.second.y());
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnd();
}

template<typename type, TYPE_VISIBLE T>
QPointF OpenGLWidget<type, T>::coordWDtoGL(QPoint point)
{
    QPointF result;
    result.setX((point.x() / m_pixelDencity.first - m_offset.first) / m_zoomFactor.first + m_MinMaxX.first);
    result.setY((m_MinMaxY.second - point.y() / m_pixelDencity.second - m_offset.second) / m_zoomFactor.second);

    return result;
}

template<typename type, TYPE_VISIBLE T>
QPoint OpenGLWidget<type, T>::coordGLtoWD(QPointF point)
{
    QPoint result;
    result.setX((point.x() * m_zoomFactor.first - m_MinMaxX.first + m_offset.first) * m_pixelDencity.first);
    result.setY(m_WDSize.second - (point.y() * m_zoomFactor.second - m_MinMaxY.first + m_offset.second) * m_pixelDencity.second);

    return result;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::resetScene()
{
    m_zoomFactor = {1, 1};
    m_lastZoomFactor = {1, 1};
    m_offset = {0, 0};
    m_lastMousePosWD = {0, 0};
    m_currMousePosWD = {0, 0};
    m_lastMousePosGL = {0, 0};
    m_currMousePosGL = {0, 0};

    if (m_graphs.empty())
        return;

    bool first{false};

    for (auto &graph : m_graphs) {
        const auto &data = graph.second;
        if (data.show == false)
            continue;

        if (!first) {
            m_MinMaxX.first = m_MinMaxX.second = data.startPoint;
            m_MinMaxY.first = m_MinMaxY.second = data.graph[0];
            first = true;
        }

        if (data.startPoint < m_MinMaxX.first)
            m_MinMaxX.first = data.startPoint;

        type endPoint = data.startPoint + data.graph.size() * m_stepGraph;
        if (endPoint > m_MinMaxX.second)
            m_MinMaxX.second = endPoint;

        m_MinMaxY.first = std::min(*std::min_element(data.graph.begin(), data.graph.end()), m_MinMaxY.first);
        m_MinMaxY.second = std::max(*std::max_element(data.graph.begin(), data.graph.end()), m_MinMaxY.second);
    }

    m_sceneSize.first = m_MinMaxX.second - m_MinMaxX.first;
    m_sceneSize.second = m_MinMaxY.second - m_MinMaxY.first;

    if (m_sceneSize.first == 0)
        m_sceneSize.first = 1;
    if (m_sceneSize.second == 0)
        m_sceneSize.second = 1;

    if (m_staticStepGrid.first <= 0)
        m_stepGrid.first = m_sceneSize.first / DEFAULT_STEP_GRID;
    if (m_staticStepGrid.second <= 0)
        m_stepGrid.second = m_sceneSize.second / DEFAULT_STEP_GRID;

    if (m_init)
        updateGLBorder();
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::updateMouseMove()
{
    m_selectedSceneEnd = m_currMousePosGL;
    if (m_selectedSceneEnd.x() > m_saveSelectedBegin.x()) {
        m_mouseMoveMode = MOUSE_MOVE_MODE::ZOOM;
        if (m_sceneMode == SCENE_MODE::HORIZONTAL) {
            m_selectedSceneBegin.setY(coordWDtoGL(QPoint{0, m_WDSize.second}).y());
            m_selectedSceneEnd.setY(coordWDtoGL(QPoint{0, 1}).y());
        } else if (m_sceneMode == SCENE_MODE::VERTICAL) {
            m_selectedSceneBegin.setX(coordWDtoGL(QPoint{1, 0}).x());
            m_selectedSceneEnd.setX(coordWDtoGL(QPoint{m_WDSize.first, 0}).x());
        } else {
            if (m_currMousePosWD.x() > m_WDSize.first)
                m_selectedSceneEnd.setX(coordWDtoGL(QPoint{m_WDSize.first, 0}).x());
            if (m_currMousePosWD.y() > m_WDSize.second)
                m_selectedSceneEnd.setY(coordWDtoGL(QPoint{0, m_WDSize.second}).y());
            if (m_currMousePosWD.y() < 0)
                m_selectedSceneEnd.setY(coordWDtoGL(QPoint{0, 1}).y());
        }
    } else {
        m_mouseMoveMode = MOUSE_MOVE_MODE::RESET;
        m_selectedSceneBegin = m_saveSelectedBegin;
    }
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::updateBorder()
{
    QRectF rec;
    rec.setLeft(coordWDtoGL({0, 0}).x());
    rec.setRight(coordWDtoGL({m_WDSize.first, 0}).x());
    rec.setBottom(coordWDtoGL({0, m_WDSize.second}).y());
    rec.setTop(coordWDtoGL({0, 0}).y());

    // X backward shift calculation
    if (rec.right() >= m_borderMaxGL.x())
        m_offset.first += (rec.right() - m_borderMaxGL.x()) * m_zoomFactor.first + m_pixelSize.first;
    else if (rec.left() <= m_borderMinGL.x())
        m_offset.first += (rec.left() - m_borderMinGL.x()) * m_zoomFactor.first - m_pixelSize.first;

    // Y backward shift calculation
    if (rec.top() >= m_borderMaxGL.y())
        m_offset.second += (rec.top() - m_borderMaxGL.y()) * m_zoomFactor.second  - m_pixelSize.second;
    else if (rec.bottom() <= m_borderMinGL.y())
        m_offset.second += (rec.bottom() - m_borderMinGL.y()) * m_zoomFactor.second + m_pixelSize.second;
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::updateGrid(bool updateFullGrid)
{
    QRectF rec;
    rec.setLeft(coordWDtoGL({0, 0}).x());
    rec.setRight(coordWDtoGL({m_WDSize.first, 0}).x());
    rec.setBottom(coordWDtoGL({0, m_WDSize.second}).y());
    rec.setTop(coordWDtoGL({0, 0}).y());

    m_axes = {coordWDtoGL(QPoint{0, 0}), coordWDtoGL(QPoint{m_WDSize.first, m_WDSize.second})};
    m_axes.first.setX(m_axes.first.x() + m_sceneSize.first / 1000 / m_zoomFactor.first);
    m_axes.second.setY(m_axes.second.y() + m_sceneSize.second / 1000 / m_zoomFactor.second);

    m_currMousePosGL = {coordWDtoGL(mapFromGlobal(this->cursor().pos()))};

    if (updateFullGrid) {
        m_gridVerticalX.clear();
        m_gridHorizontalY.clear();

        float sizeX = m_MinMaxX.first;
        while (sizeX < m_borderMaxGL.x() && sizeX > m_borderMinGL.x()) {
            m_gridVerticalX.push_back(sizeX);
            sizeX += m_stepGrid.first;
        }
        sizeX = m_MinMaxX.first - m_stepGrid.first;
        while (sizeX < m_borderMaxGL.x() && sizeX > m_borderMinGL.x()) {
            m_gridVerticalX.push_back(sizeX);
            sizeX -= m_stepGrid.first;
        }

        float sizeY = m_MinMaxY.first;
        while (sizeY < m_borderMaxGL.y() && sizeY > m_borderMinGL.y()) {
            m_gridHorizontalY.push_back(sizeY);
            sizeY += m_stepGrid.second;
        }
        sizeY = m_MinMaxY.first - m_stepGrid.second;
        while (sizeY < m_borderMaxGL.y() && sizeY > m_borderMinGL.y()) {
            m_gridHorizontalY.push_back(sizeY);
            sizeY -= m_stepGrid.second;
        }
    }
    if (m_lastZoomFactor != m_zoomFactor) {
        bool work = false;
        while (m_lastZoomFactor.first * ZOOM_FACTOR_GRID < m_zoomFactor.first) {
            work = true;
            m_lastZoomFactor.first *= ZOOM_FACTOR_GRID;
            size_t size = m_gridVerticalX.size();
            float k = (float)m_stepGrid.first / m_lastZoomFactor.first;
            for (size_t i = 0; i < size; ++i) {
                m_gridVerticalX.push_back(m_gridVerticalX[i] + k);
            }
        }
        if (!work && m_lastZoomFactor.first != START_ZOOM) {
            while (m_lastZoomFactor.first > m_zoomFactor.first) {
                m_lastZoomFactor.first /= ZOOM_FACTOR_GRID;
                size_t size = m_gridVerticalX.size() / ZOOM_FACTOR_GRID;
                for (size_t i = 0; i < size; ++i) {
                    m_gridVerticalX.pop_back();
                }
            }
        }

        work = false;
        while (m_lastZoomFactor.second * ZOOM_FACTOR_GRID < m_zoomFactor.second) {
            m_lastZoomFactor.second *= ZOOM_FACTOR_GRID;
            size_t size = m_gridHorizontalY.size();
            float k = (float)m_stepGrid.second / m_lastZoomFactor.second;
            for (size_t i = 0; i < size; ++i) {
                m_gridHorizontalY.push_back(m_gridHorizontalY[i] + k);
            }
        }
        if (!work && m_lastZoomFactor.second != START_ZOOM) {
            while (m_lastZoomFactor.second > m_zoomFactor.second) {
                m_lastZoomFactor.second /= ZOOM_FACTOR_GRID;
                size_t size = m_gridHorizontalY.size() / ZOOM_FACTOR_GRID;
                for (size_t i = 0; i < size; ++i) {
                    m_gridHorizontalY.pop_back();
                }
            }
        }
    }

    m_textVerticalX.clear();
    m_textHorizontalY.clear();
    m_valueVerticalX.clear();
    m_valueHorizontalY.clear();

    m_textVerticalX.reserve(m_sceneSize.first / m_stepGrid.first);
    m_textHorizontalY.reserve(m_sceneSize.second / m_stepGrid.second);
    m_valueVerticalX.reserve(m_sceneSize.first / m_stepGrid.first);
    m_valueHorizontalY.reserve(m_sceneSize.second / m_stepGrid.second);

    for (size_t i = 0; i < m_gridVerticalX.size(); i++)
        if (m_gridVerticalX[i] > m_axes.first.x() && m_gridVerticalX[i] < m_axes.second.x()) {
            m_textVerticalX.push_back(coordGLtoWD({m_gridVerticalX[i], 0}).x());
            m_valueVerticalX.push_back(m_gridVerticalX[i]);
        }

    for (size_t i = 0; i < m_gridHorizontalY.size(); i++) {
        if (m_gridHorizontalY[i] < m_axes.first.y() && m_gridHorizontalY[i] > m_axes.second.y()) {
            m_textHorizontalY.push_back(coordGLtoWD({0, m_gridHorizontalY[i]}).y());
            m_valueHorizontalY.push_back(m_gridHorizontalY[i]);
        }
    }

    std::sort(m_textVerticalX.begin(), m_textVerticalX.end());
    std::sort(m_textHorizontalY.begin(), m_textHorizontalY.end());
    std::sort(m_valueVerticalX.begin(), m_valueVerticalX.end());
    std::sort(m_valueHorizontalY.begin(), m_valueHorizontalY.end(), std::greater<float>());

    m_textVerticalX.push_back(coordGLtoWD({m_currMousePosGL.x(), 0}).x());
    m_textHorizontalY.push_back(coordGLtoWD({0, m_currMousePosGL.y()}).y());
    m_valueVerticalX.push_back(m_currMousePosGL.x());
    m_valueHorizontalY.push_back(m_currMousePosGL.y());

    m_signal->triggerSignalTextValues(m_id);
}

template<typename type, TYPE_VISIBLE T>
void OpenGLWidget<type, T>::updateGLBorder()
{
    // Возможная ошибка при захвате контекста
    if (false) {
        makeCurrent();
        resizeGL(width(), height());
        doneCurrent();
    } else {
        resize(width() - 1, height());
        resize(width() + 1, height());
    }

    updateGrid(true);
    update();
}

#endif // OPENGL_WIDGET_H
