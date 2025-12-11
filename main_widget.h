#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include "opengl_widget.h"

#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QStyle>
#include <QDialog>
#include <QDoubleSpinBox>

///
/// \brief The MainWidget class - widget for interaction with visualized data
///
template<typename type, TYPE_VISIBLE T>
class MainWidget : public QWidget
{
public:

    // --- Helper aliases ---

    using OGLW = OpenGLWidget<type, T>;

    // --- Constructors/destructors ---

    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() = default;

    // --- Main methods ---

    ///
    /// \brief addGraph - add graph to tab
    /// \param idTab - id of tab be interacted with
    /// \param graph - array of graph values
    /// \param name - item name
    /// \return - if id > 0, then id of created graph, else if id == -1, then graph isn't create
    ///
    int addGraph(int idTab, std::vector<type> &graph, QString name = "Graph");

    ///
    /// \brief addGraph - add graph to tab and set graph color
    /// \param idTab - id of tab be interacted with
    /// \param graph - array of graph values
    /// \param color - item color
    /// \param name - item name
    /// \return - id, if id > 0, then id of created graph, else if id == -1, then graph isn't create
    ///
    int addGraph(int idTab, std::vector<type> &graph, QRgb color, QString name = "Graph");

    ///
    /// \brief addTab - add tab to widget
    /// \param name - item name
    /// \return - id of created tab
    ///
    int addTab(QString name);

    ///
    /// \brief deleteTab - delete tab from widget
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool deleteTab(int idTab);

    ///
    /// \brief deleteGraph - delete graph from tab
    /// \param idGraph - id of graph be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool deleteGraph(int idGraph);

    ///
    /// \brief updateScene - update scene
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool updateScene(int idTab);

    ///
    /// \brief swapMouseButton - swap mouse button
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool swapMouseButton(int idTab);

    ///
    /// \brief swapVHButtons - swap buttons which will change scene in vertical and horizontal space
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool swapVHButtons(int idTab);

    // --- Setters ---

    ///
    /// \brief setTabsWidgetPos - set position for tabs
    /// \param pos - position for tabs
    ///
    void setTabsWidgetPos(QTabWidget::TabPosition pos);

    ///
    /// \brief setCurrentTab - set current tab
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool setCurrentTab(int idTab);

    ///
    /// \brief setAutoUpdateScene - set update scene auto
    /// \param set - whether to update scene auto
    ///
    void setUpdateSceneAuto(bool set);

    ///
    /// \brief setStepGraph - set distance between each value on all graphs in tab
    /// \param idTab - id of tab be interacted with
    /// \param step - distance between each value on graph
    /// \return - true is all good, false is mistake
    ///
    bool setStepGraph(int idTab, double step);

    ///
    /// \brief setStepGrid - set distance between each part of the grid in all tabs
    /// \param step - distance between each part of the grid
    ///
    void setStepGrid(std::pair<double, double> step);

    ///
    /// \brief setStepGrid - set distance between each part of the grid in all tabs
    /// \param idTab - id of tab be interacted with
    /// \param step - distance between each part of the grid
    /// \return - true is all good, false is mistake
    ///
    bool setStepGrid(int idTab, std::pair<double, double> step);

    ///
    /// \brief setStartPointGraph - set point of beginning of graph
    /// \param idGraph - id of graph be interacted with
    /// \param startPoint - point of beginning of graph
    /// \return - true is all good, false is mistake
    ///
    bool setStartPointGraph(int idGraph, double startPoint);

    ///
    /// \brief setGraphMode - set mode in which graph will display in all tabs
    /// \param mode - mode in which graph will display
    ///
    void setGraphMode(typename OGLW::GRAPH_MODE mode);

    ///
    /// \brief setGraphMode - set mode in which graph will display in tab
    /// \param idTab - id of tab be interacted with
    /// \param mode - mode in which graph will display
    /// \return - true is all good, false is mistake
    ///
    bool setGraphMode(int idTab, typename OGLW::GRAPH_MODE mode);

    ///
    /// \brief setSceneMode - set mode in which scene will change in all tabs
    /// \param mode - mode in which scene will change
    ///
    void setSceneMode(typename OGLW::SCENE_MODE mode);

    ///
    /// \brief setSceneMode - set mode in which scene will change in tab
    /// \param idTab - id of tab be interacted with
    /// \param mode - mode in which scene will change
    /// \return - true is all good, false is mistake
    ///
    bool setSceneMode(int idTab, typename OGLW::SCENE_MODE mode);

    ///
    /// \brief setResetSceneButton - set button which will reset scene
    /// \param idTab - id of tab be interacted with
    /// \param button - button which will reset scene
    /// \return - true is all good, false is mistake
    ///
    bool setResetSceneButton(int idTab, Qt::Key button);

    ///
    /// \brief setCancelSelectButton - set button which will cancel selected scene
    /// \param idTab - id of tab be interacted with
    /// \param button - button which will cancel selected scene
    /// \return - true is all good, false is mistake
    ///
    bool setCancelSelectButton(int idTab, Qt::Key button);

    ///
    /// \brief setValuesGraph - set array of graph values
    /// \param idGraph - id of graph be interacted with
    /// \param graph - array of graph values
    /// \return - true is all good, false is mistake
    ///
    bool setValuesGraph(int idGraph, const std::vector<type> &graph);

    ///
    /// \brief setNameGraph - set name of graph
    /// \param idGraph - id of graph be interacted with
    /// \param name - name of graph
    /// \return - true is all good, false is mistake
    ///
    bool setNameGraph(int idGraph, QString name);

    ///
    /// \brief setGraphVisible - whether to display graph
    /// \param idGraph - id of graph be interacted with
    /// \param show - whether to show item
    /// \return - true is all good, false is mistake
    ///
    bool setGraphVisible(int idGraph, bool show);

    ///
    /// \brief setGridVisible - whether to display grid in all tabs
    /// \param show - whether to show item
    ///
    void setGridVisible(bool show);

    ///
    /// \brief setGridVisible - whether to display grid in tab
    /// \param idTab - id of tab be interacted with
    /// \param show - whether to show item
    /// \return - true is all good, false is mistake
    ///
    bool setGridVisible(int idTab, bool show);

    ///
    /// \brief setGridCursorVisible - whether to display cursor grid in all tabs
    /// \param show - whether to show item
    ///
    void setGridCursorVisible(bool show);

    ///
    /// \brief setGridCursorVisible - whether to display cursor grid in tab
    /// \param idTab - id of tab be interacted with
    /// \param show - whether to show item
    /// \return - true is all good, false is mistake
    ///
    bool setGridCursorVisible(int idTab, bool show);

    ///
    /// \brief setAxesName - set names of axes
    /// \param idTab - id of tab be interacted with
    /// \param xAxisName - name of X axis
    /// \param yAxisName - name of Y axis
    /// \return - true is all good, false is mistake
    ///
    bool setAxesName(int idTab, QString xAxisName, QString yAxisName);

    ///
    /// \brief setColorGraph - set graph color in all tabs
    /// \param color - item color
    ///
    void setColorGraph(QRgb color);

    ///
    /// \brief setColorGraph - set graph color
    /// \param idGraph - id of graph be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorGraph(int idGraph, QRgb color);

    ///
    /// \brief setColorText - set text color in all tabs
    /// \param color - item color
    ///
    void setColorText(QRgb color);

    ///
    /// \brief setColorText - set text color in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorText(int idTab, QRgb color);

    ///
    /// \brief setColorBack - set background color in all tabs
    /// \param color - item color
    ///
    void setColorBack(QRgb color);

    ///
    /// \brief setColorBack - set background color in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorBack(int idTab, QRgb color);

    ///
    /// \brief setColorGrid - set grid color in all tabs
    /// \param color - item color
    ///
    void setColorGrid(QRgb color);

    ///
    /// \brief setColorGrid - set grid color in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorGrid(int idTab, QRgb color);

    ///
    /// \brief setColorGridCursor - set cursor grid color in all tabs
    /// \param color - item color
    ///
    void setColorGridCursor(QRgb color);

    ///
    /// \brief setColorGridCursor - set cursor grid color in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorGridCursor(int idTab, QRgb color);

    ///
    /// \brief setColorAxes - set axes color in all tabs
    /// \param color - item color
    ///
    void setColorAxes(QRgb color);

    ///
    /// \brief setColorAxes - set axes color in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorAxes(int idTab, QRgb color);

    ///
    /// \brief setColorBackCursor - set background color for cursor values in all tabs
    /// \param color - item color
    ///
    void setColorBackCursor(QRgb color);

    ///
    /// \brief setColorBackCursor - set background color for cursor values in tab
    /// \param idTab - id of tab be interacted with
    /// \param color - item color
    /// \return - true is all good, false is mistake
    ///
    bool setColorBackCursor(int idTab, QRgb color);

    ///
    /// \brief setFontText - set font for text in all tabs
    /// \param font - font ('name font')
    ///
    void setFontText(QString font);

    ///
    /// \brief setFontText - set font for text in tab
    /// \param idTab - id of tab be interacted with
    /// \param font - font ('name font')
    /// \return - true is all good, false is mistake
    ///
    bool setFontText(int idTab, QString font);

    ///
    /// \brief setWidthGraph - set line width graph in all tabs
    /// \param width - line width
    ///
    void setWidthGraph(float width);

    ///
    /// \brief setWidthGraph - set line width graph in tab
    /// \param width - line width
    /// \param idTab - id of tab be interacted with
    /// \return - true is all good, false is mistake
    ///
    bool setWidthGraph(float width, int idTab);

    ///
    /// \brief setWidthGrid - set line width grid in all tabs
    /// \param width - line width
    ///
    void setWidthGrid(float width);

    ///
    /// \brief setWidthGrid - set line width grid in tab
    /// \param idTab - id of tab be interacted with
    /// \param width - line width
    /// \return - true is all good, false is mistake
    ///
    bool setWidthGrid(int idTab, float width);

    ///
    /// \brief setWidthGridCursor - set line width grid cursor in all tabs
    /// \param width - line width
    ///
    void setWidthGridCursor(float width);

    ///
    /// \brief setWidthGridCursor - set line width grid cursor in tab
    /// \param idTab - id of tab be interacted with
    /// \param width - line width
    /// \return - true is all good, false is mistake
    ///
    bool setWidthGridCursor(int idTab, float width);

    ///
    /// \brief setWidthAxes - set line width axes in all tabs
    /// \param width - line width
    ///
    void setWidthAxes(float width);

    ///
    /// \brief setWidthAxes - set line width axes in tab
    /// \param idTab - id of tab be interacted with
    /// \param width - line width
    /// \return - true is all good, false is mistake
    ///
    bool setWidthAxes(int idTab, float width);

    // --- Getters ---

    ///
    /// \brief getSignal - get class Signal, which emit different signals
    /// \return - class Signal
    ///
    WidgetSignals *getSignal();

    ///
    /// \brief getCurrentTab - get current tab
    /// \return - current tab
    ///
    int getCurrentTab();

private:

    ///
    /// \brief updateGridValues - update grid and cursor grid values in tab
    /// \param idTab - id of tab be interacted with
    ///
    void updateGridValues(int idTab);

    ///
    /// \brief convertColorName - convert QRgb in QString{"rgb(r, g, b)"}
    /// \param color - item color
    /// \return - conversion result, QString{"rgb(r, g, b)"}
    ///
    QString convertColorName(QRgb color);

private:

    // --- Helper structs ---

    ///
    /// \brief The Graph class - store elements of legend
    ///
    struct Graph {
        QPushButton *button; ///< Turn on/off graph
        QLabel       *label; ///< Graph name
        QRgb          color; ///< Graph color
        bool           show; ///< Show or unshow graph

        // --- Constructors/destructors ---

        Graph() = default;
        Graph(QPushButton *button, QLabel *label, QRgb color)
            : button{button}, label{label}, color{color}, show{true}
        {}
        ~Graph() = default;
    };

    ///
    /// \brief The Tab class - keep all elements of tab
    ///
    struct Tab {
        OGLW                      *OGLWidget; ///< Responsible for rendering
        QHBoxLayout           *buttonsLayout; ///< Is legend
        QWidget                       *XAxis; ///< Store labels on the X axis
        QWidget                       *YAxis; ///< Store labels on the Y axis
        int                         idWidget; ///< Tab id in QTabWidget
        bool                       deleteTab; ///< Is tab removed
        std::pair<QString, QString> axesName; ///< Axes name in tab
        QRgb                       colorText; ///< Text color in tab
        QRgb                 colorBackCursor; ///< Cursor background color in tab
        QString                         font; ///< Font for text in tab
    };

    // --- Fields ---

    std::vector<Tab>               m_tabs; ///< Vector structures tab
    std::vector<Graph>           m_graphs; ///< Vector structures graph
    std::vector<int>        m_graphsIdTab; ///< Vector stores tab numbers belonging to corresponding graphs
    QTabWidget               *m_tabWidget; ///< Responsible for tabs
    WidgetSignals                m_signal; ///< Emit signals

    typename OGLW::GRAPH_MODE m_graphMode; ///< Mode in which graph will display in all tabs
    typename OGLW::SCENE_MODE m_sceneMode; ///< Mode in which scene will change in all tabs

    bool                m_updateSceneAuto; ///<
    std::pair<double, double>  m_stepGrid; ///<

    QRgb                     m_colorGraph; ///< Graph color in tabs
    QRgb                      m_colorText; ///< Text color in tabs
    QRgb                      m_colorBack; ///< Background color in tabs
    QRgb                      m_colorGrid; ///< Grid color in tabs
    QRgb                m_colorGridCursor; ///< Cursor grid color in tabs
    QRgb                      m_colorAxes; ///< Axes color in tabs
    QRgb                m_colorBackCursor; ///< Background color for cursor in tabs

    float                    m_widthGraph; ///< Graph line width in tabs
    float                     m_widthGrid; ///< Grid line width in tabs
    float               m_widthGridCursor; ///< Cursor grid line width in tabs
    float                     m_widthAxes; ///< Axes line width in tabs

    QString                        m_font; ///< Font for text in tabs
};

template<typename type, TYPE_VISIBLE T>
MainWidget<type, T>::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumSize(0, 0);

    m_tabWidget = new QTabWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_tabWidget);
    this->setLayout(mainLayout);

    m_graphMode = OGLW::GRAPH_MODE::LINE;
    m_sceneMode = OGLW::SCENE_MODE::BOTH;
    m_updateSceneAuto = true;
    m_colorText = m_colorAxes = qRgb(0, 0, 0);
    m_colorBack = qRgb(255, 255, 255);
    m_colorGrid = qRgb(175, 175, 175);
    m_colorGridCursor = qRgba(50, 50, 50, 200);
    m_colorBackCursor = qRgb(230, 230, 230);
    m_widthGraph = m_widthGrid = m_widthGridCursor = m_widthAxes = 1;
    m_font = "'Arial'";

    connect(&m_signal, &WidgetSignals::updateTextValues, this, [this](int id) {
        updateGridValues(id);
    });
    connect(m_tabWidget, &QTabWidget::currentChanged, this, [this]([[maybe_unused]] int id) {
        m_signal.triggerSignalCurrentTab(getCurrentTab());
    });
}

template<typename type, TYPE_VISIBLE T>
int MainWidget<type, T>::addGraph(int idTab, std::vector<type> &graph, QString name)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return -1;

    int idGraph = m_graphsIdTab.size();
    m_graphsIdTab.push_back(idTab);

    typename OGLW::GraphData graphData{graph, m_colorGraph};
    m_tabs[idTab].OGLWidget->addGraph(idGraph, graphData);

    QPushButton *button = new QPushButton{};
    button->setFixedSize(16, 16);
    button->setStyleSheet(("background-color: " + convertColorName(m_colorGraph) + "; border: 1px solid black;"));
    m_tabs[idTab].buttonsLayout->addWidget(button);

    QLabel *label = new QLabel{name};
    label->setFixedHeight(16);
    label->setStyleSheet("color: " + convertColorName(m_colorText) + ";");
    m_tabs[idTab].buttonsLayout->addWidget(label);

    m_graphs.push_back(Graph{button, label, m_colorGraph});

    connect(button, &QPushButton::clicked, [this, idGraph]() {
        Graph &g = m_graphs[idGraph];

        if (g.show)
            g.button->setStyleSheet("background-color: white; border: 1px solid black;");
        else
            g.button->setStyleSheet(QString("background-color: " + convertColorName(g.color)
                                            + "; border: 1px solid black;"));

        g.show ^= true;
        setGraphVisible(idGraph, g.show);
    });

    return idGraph;
}

template<typename type, TYPE_VISIBLE T>
int MainWidget<type, T>::addGraph(int idTab, std::vector<type> &graph, QRgb color, QString name)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return -1;

    int idGraph = m_graphsIdTab.size();
    m_graphsIdTab.push_back(idTab);

    typename OGLW::GraphData graphData{graph, color};
    m_tabs[idTab].OGLWidget->addGraph(idGraph, graphData);

    QPushButton *button = new QPushButton{};
    button->setFixedSize(16, 16);
    button->setStyleSheet(("background-color: " + convertColorName(color) + "; border: 1px solid black;"));
    m_tabs[idTab].buttonsLayout->addWidget(button);

    QLabel *label = new QLabel{name};
    label->setFixedHeight(16);
    label->setStyleSheet("color: " + convertColorName(m_colorText) + "; font-family: " + m_tabs[idTab].font + ";");
    m_tabs[idTab].buttonsLayout->addWidget(label);

    m_graphs.push_back(Graph{button, label, color});

    connect(button, &QPushButton::clicked, [this, idGraph]() {
        Graph &g = m_graphs[idGraph];

        if (g.show)
            g.button->setStyleSheet("background-color: white; border: 1px solid black;");
        else
            g.button->setStyleSheet(QString("background-color: " + convertColorName(g.color)
                                            + "; border: 1px solid black;"));

        g.show ^= true;
        setGraphVisible(idGraph, g.show);
    });

    return idGraph;
}

template<typename type, TYPE_VISIBLE T>
int MainWidget<type, T>::addTab(QString name)
{
    QWidget *tab = new QWidget();
    QVBoxLayout *mainL = new QVBoxLayout();
    QVBoxLayout *GLWAxis = new QVBoxLayout();
    QHBoxLayout *GLWBut = new QHBoxLayout();
    QHBoxLayout *topLayout = new QHBoxLayout();
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QWidget *XAxis = new QWidget();
    QWidget *YAxis = new QWidget();

    int idTab = m_tabs.size();
    tab->setStyleSheet("background-color: " + convertColorName(m_colorBack) + ";");

    m_tabs.push_back(Tab{});
    m_tabs[idTab].OGLWidget = new OGLW{idTab};
    m_tabs[idTab].buttonsLayout = buttonsLayout;
    m_tabs[idTab].XAxis = XAxis;
    m_tabs[idTab].YAxis = YAxis;
    m_tabs[idTab].deleteTab = false;
    m_tabs[idTab].idWidget = m_tabWidget->count();
    m_tabs[idTab].axesName = {"X", "Y"};
    m_tabs[idTab].colorText = m_colorText;
    m_tabs[idTab].colorBackCursor = m_colorBackCursor;
    m_tabs[idTab].font = m_font;
    m_tabs[idTab].OGLWidget->setGraphMode(m_graphMode);
    m_tabs[idTab].OGLWidget->setSceneMode(m_sceneMode);
    m_tabs[idTab].OGLWidget->setStepGrid(m_stepGrid);
    m_tabs[idTab].OGLWidget->setUpdateSceneAuto(m_updateSceneAuto);
    m_tabs[idTab].OGLWidget->setSignal(&m_signal);
    m_tabs[idTab].OGLWidget->setColorBack(m_colorBack);
    m_tabs[idTab].OGLWidget->setColorGrid(m_colorGrid);
    m_tabs[idTab].OGLWidget->setColorGridCursor(m_colorGridCursor);
    m_tabs[idTab].OGLWidget->setColorAxes(m_colorAxes);
    m_tabs[idTab].OGLWidget->setWidthGraph(m_widthGraph);
    m_tabs[idTab].OGLWidget->setWidthGrid(m_widthGrid);
    m_tabs[idTab].OGLWidget->setWidthGridCursor(m_widthGridCursor);
    m_tabs[idTab].OGLWidget->setWidthAxes(m_widthAxes);

    QPushButton *settingsButton = new QPushButton();
    settingsButton->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    settingsButton->setFixedWidth(30);
    settingsButton->setStyleSheet(R"(
    QPushButton {
        border: 1px solid rgba(0, 0, 0, 0.18);
        border-radius: 6px;
        padding: 4px;
    }
    QPushButton:hover {
        background: rgba(0, 0, 0, 0.06);
    }
    QPushButton:pressed {
        background: rgba(0, 0, 0, 0.12);
    })");

    QDialog *settingsDialog = new QDialog(this);
    settingsDialog->setWindowTitle("Настройки");
    settingsDialog->setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    settingsDialog->setFixedSize(250, 250);

    QObject::connect(settingsButton, &QPushButton::clicked, [ = ]() {
        settingsDialog->exec();
    });

    auto makeDoubleSpin = [&](double value, double min, double max, double step, int decimals) {
        QDoubleSpinBox *s = new QDoubleSpinBox(settingsDialog);
        s->setRange(min, max);
        s->setSingleStep(step);
        s->setDecimals(decimals);
        s->setValue(value);
        s->setFixedWidth(60);
        return s;
    };

    auto makeExpSpin = [&]() {
        QSpinBox *e = new QSpinBox(settingsDialog);
        e->setRange(-20, 20);
        e->setValue(0);
        e->setSingleStep(1);
        e->setFixedWidth(50);
        return e;
    };

    double globalMin = -100;
    double globalMax = 100;
    int decimals = 3;
    double step = 1;

    QLabel *lblMinX = new QLabel("Min X", settingsDialog);
    QDoubleSpinBox *spinMinX = makeDoubleSpin(0.0, globalMin, globalMax, step, decimals);
    QSpinBox *expMinX = makeExpSpin();

    QLabel *lblMaxX = new QLabel("Max X", settingsDialog);
    QDoubleSpinBox *spinMaxX = makeDoubleSpin(1.0, globalMin, globalMax, step, decimals);
    QSpinBox *expMaxX = makeExpSpin();

    QLabel *lblMinY = new QLabel("Min Y", settingsDialog);
    QDoubleSpinBox *spinMinY = makeDoubleSpin(0.0, globalMin, globalMax, step, decimals);
    QSpinBox *expMinY = makeExpSpin();

    QLabel *lblMaxY = new QLabel("Max Y", settingsDialog);
    QDoubleSpinBox *spinMaxY = makeDoubleSpin(1.0, globalMin, globalMax, step, decimals);
    QSpinBox *expMaxY = makeExpSpin();

    QVBoxLayout *dialogLayout = new QVBoxLayout(settingsDialog);

    auto addRow = [&](QLabel * label, QWidget * mantissa, QWidget * expWidget) {
        QHBoxLayout *row = new QHBoxLayout();
        row->addWidget(label);
        row->addStretch(1);
        row->addWidget(mantissa);
        row->addWidget(new QLabel("×10^", settingsDialog));
        row->addWidget(expWidget);
        dialogLayout->addLayout(row);
    };

    addRow(lblMinX, spinMinX, expMinX);
    addRow(lblMaxX, spinMaxX, expMaxX);

    addRow(lblMinY, spinMinY, expMinY);
    addRow(lblMaxY, spinMaxY, expMaxY);

    settingsDialog->setLayout(dialogLayout);

    auto computeValue = [](double value, int exp) -> double {
        return value * std::pow(10.0, exp);
    };

    auto updateX = [ = ]() {
        double minValue = spinMinX->value();
        int minExp = expMinX->value();
        double maxValue = spinMaxX->value();
        int maxExp = expMaxX->value();

        double minX = computeValue(minValue, minExp);
        double maxX = computeValue(maxValue, maxExp);

        if (minX >= maxX) {
            return;
        }

        m_tabs[idTab].OGLWidget->setMinMaxXScene(minX, maxX);
    };

    auto updateY = [ = ]() {
        double minValue = spinMinY->value();
        int minExp = expMinY->value();
        double maxValue = spinMaxY->value();
        int maxExp = expMaxY->value();

        double minY = computeValue(minValue, minExp);
        double maxY = computeValue(maxValue, maxExp);

        if (minY >= maxY) {
            return;
        }

        m_tabs[idTab].OGLWidget->setMinMaxYScene(minY, maxY);
    };

    QObject::connect(spinMinX, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [ = ](double) {
        updateX();
    });
    QObject::connect(spinMaxX, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [ = ](double) {
        updateX();
    });
    QObject::connect(spinMinY, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [ = ](double) {
        updateY();
    });
    QObject::connect(spinMaxY, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [ = ](double) {
        updateY();
    });

    QObject::connect(expMinX, QOverload<int>::of(&QSpinBox::valueChanged), [ = ](int) {
        updateX();
    });
    QObject::connect(expMaxX, QOverload<int>::of(&QSpinBox::valueChanged), [ = ](int) {
        updateX();
    });
    QObject::connect(expMinY, QOverload<int>::of(&QSpinBox::valueChanged), [ = ](int) {
        updateY();
    });
    QObject::connect(expMaxY, QOverload<int>::of(&QSpinBox::valueChanged), [ = ](int) {
        updateY();
    });

    GLWAxis->addWidget(m_tabs[idTab].OGLWidget, 20);
    GLWAxis->addWidget(XAxis, 1);

    YAxis->setMinimumWidth(35);
    GLWBut->addWidget(YAxis, 1);
    GLWBut->addLayout(GLWAxis, 20);

    topLayout->addLayout(buttonsLayout, 20);
    topLayout->addWidget(settingsButton, 1);

    mainL->addLayout(topLayout, 1);
    mainL->addSpacing(10);
    mainL->addLayout(GLWBut, 10);

    tab->setLayout(mainL);
    m_tabWidget->addTab(tab, name);

    return idTab;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::deleteTab(int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].deleteTab = true;
    QWidget *widget = m_tabWidget->widget(m_tabs[idTab].idWidget);
    m_tabWidget->removeTab(m_tabs[idTab].idWidget);
    widget->deleteLater();

    for (auto &graphIdTab : m_graphsIdTab)
        if (graphIdTab == idTab)
            graphIdTab = -1;

    for (int i = idTab + 1; i < m_tabs.size(); ++i) {
        if (m_tabs[i].deleteTab)
            continue;

        --m_tabs[i].idWidget;
    }

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::deleteGraph(int idGraph)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_tabs[m_graphsIdTab[idGraph]].OGLWidget->deleteGraph(idGraph);
    m_tabs[m_graphsIdTab[idGraph]].graphs[idGraph].button->deleteLater();
    m_tabs[m_graphsIdTab[idGraph]].graphs[idGraph].label->deleteLater();
    m_graphsIdTab[idGraph] = -1;

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::updateScene(int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->updateScene();

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::swapMouseButton(int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->swapMouseButton();

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setTabsWidgetPos(QTabWidget::TabPosition pos)
{
    m_tabWidget->setTabPosition(pos);
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setCurrentTab(int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    int id{};
    for (int i = 0; i < idTab; ++i) {
        if (!m_tabs[i].deleteTab)
            ++id;
    }

    m_tabWidget->setCurrentIndex(id);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setUpdateSceneAuto(bool set)
{
    m_updateSceneAuto = set;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setUpdateSceneAuto(set);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setGraphVisible(int idGraph, bool show)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_graphs[idGraph].show = show;
    m_tabs[m_graphsIdTab[idGraph]].OGLWidget->setGraphVisible(idGraph, show);

    if (show)
        m_graphs[idGraph].button->setStyleSheet(QString("background-color: " + convertColorName(m_graphs[idGraph].color)
                                                + "; border: 1px solid black;"));
    else
        m_graphs[idGraph].button->setStyleSheet("background-color: white; border: 1px solid black;");

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setGridVisible(bool show)
{
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setGridVisible(show);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setGridVisible(int idTab, bool show)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setGridVisible(show);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setGridCursorVisible(bool show)
{
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setGridCursorVisible(show);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setGridCursorVisible(int idTab, bool show)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setGridCursorVisible(show);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setStepGraph(int idTab, double step)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setStepGraph(step);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setStepGrid(std::pair<double, double> step)
{
    m_stepGrid = step;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setStepGrid(step);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setStepGrid(int idTab, std::pair<double, double> step)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setStepGrid(step);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setStartPointGraph(int idGraph, double startPoint)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_tabs[m_graphsIdTab[idGraph]].OGLWidget->setStartPointGraph(idGraph, startPoint);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setGraphMode(typename OGLW::GRAPH_MODE mode)
{
    m_graphMode = mode;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setGraphMode(mode);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setGraphMode(int idTab, typename OGLW::GRAPH_MODE mode)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setGraphMode(mode);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setSceneMode(typename OGLW::SCENE_MODE mode)
{
    m_sceneMode = mode;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setSceneMode(mode);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setSceneMode(int idTab, typename OGLW::SCENE_MODE mode)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setSceneMode(mode);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setResetSceneButton(int idTab, Qt::Key button)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setResetSceneButton(button);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setCancelSelectButton(int idTab, Qt::Key button)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setCancelSelectButton(button);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::swapVHButtons(int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->swapVHButtons();

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setValuesGraph(int idGraph, const std::vector<type> &graph)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_tabs[m_graphsIdTab[idGraph]].OGLWidget->setValuesGraph(idGraph, graph);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setNameGraph(int idGraph, QString name)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_graphs[idGraph].label->setText(name);

    return true;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setAxesName(int idTab, QString xAxisName, QString yAxisName)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].axesName = {xAxisName, yAxisName};

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorGraph(QRgb color)
{
    m_colorGraph = color;

    for (size_t i = 0; i < m_graphsIdTab.size(); ++i) {
        if (m_graphsIdTab[i] == -1)
            continue;

        m_tabs[m_graphsIdTab[i]].OGLWidget->setColorGraph(i, color);
        m_graphs[i].color = color;
        if (m_graphs[i].turn)
            m_graphs[i].button->setStyleSheet(
                QString("background-color: " + convertColorName(color) + "; border: 1px solid black;"));
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorGraph(int idGraph, QRgb color)
{
    if (m_graphsIdTab.size() <= idGraph || m_graphsIdTab[idGraph] == -1)
        return false;

    m_tabs[m_graphsIdTab[idGraph]].OGLWidget->setColorGraph(idGraph, color);
    m_graphs[idGraph].color = color;
    if (m_graphs[idGraph].show)
        m_graphs[idGraph].button->setStyleSheet(
            QString("background-color: " + convertColorName(color) + "; border: 1px solid black;"));

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorText(QRgb color)
{
    m_colorText = color;

    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.colorText = color;

        for (auto &graph : tab.graphs)
            graph.label->setStyleSheet("color: " + convertColorName(color) + ";");
    }

}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorText(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].colorText = color;
    for (auto &graph : m_tabs[idTab])
        graph.label->setStyleSheet("color: " + convertColorName(color) + ";");

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorBack(QRgb color)
{
    m_colorBack = color;

    this->setStyleSheet("background-color: " + convertColorName(color) + ";");
    //_tabWidget->setStyleSheet("background-color: " + getColorName(_colorBack) + ";");

    for (size_t i = 0; i < m_tabWidget->count(); ++i) {
        QWidget *widget = m_tabWidget->widget(i);
        widget->setStyleSheet("background-color: " + convertColorName(color) + ";");
    }
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setColorBack(color);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorBack(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    QWidget *widget = m_tabWidget->widget(m_tabs[idTab].idWidget);
    widget->setStyleSheet("background-color: " + convertColorName(color) + ";");

    m_tabs[idTab].OGLWidget->setColorBack(color);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorGrid(QRgb color)
{
    m_colorGrid = color;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setColorGrid(color);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorGrid(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setColorGrid(color);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorGridCursor(QRgb color)
{
    m_colorGridCursor = color;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setColorGridCursor(color);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorGridCursor(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setColorGridCursor(color);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorAxes(QRgb color)
{
    m_colorAxes = color;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setColorAxes(color);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorAxes(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setColorAxes(color);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setColorBackCursor(QRgb color)
{
    m_colorBackCursor = color;
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setColorBackCursor(int idTab, QRgb color)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].colorBackCursor = color;

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setFontText(QString font)
{
    m_font = font;

    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.font = font;

        for (auto &graph : tab.graphs)
            graph.label->setStyleSheet("font-family: " + font + ";");
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setFontText(int idTab, QString font)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].font = font;
    for (auto &graph : m_tabs[idTab])
        graph.label->setStyleSheet("font-family: " + font + ";");

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setWidthGraph(float width)
{
    m_widthGraph = width;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setWidthGraph(width);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setWidthGraph(float width, int idTab)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setWidthGraph(width);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setWidthGrid(float width)
{
    m_widthGrid = width;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setWidthGrid(width);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setWidthGrid(int idTab, float width)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setWidthGrid(width);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setWidthGridCursor(float width)
{
    m_widthGridCursor = width;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setWidthGridCursor(width);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setWidthGridCursor(int idTab, float width)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setWidthGridCursor(width);

    return true;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::setWidthAxes(float width)
{
    m_widthAxes = width;
    for (auto &tab : m_tabs) {
        if (tab.deleteTab)
            continue;

        tab.OGLWidget->setWidthAxes(width);
    }
}

template<typename type, TYPE_VISIBLE T>
bool MainWidget<type, T>::setWidthAxes(int idTab, float width)
{
    if (m_tabs.size() <= idTab || m_tabs[idTab].deleteTab)
        return false;

    m_tabs[idTab].OGLWidget->setWidthAxes(width);

    return true;
}

template<typename type, TYPE_VISIBLE T>
WidgetSignals *MainWidget<type, T>::getSignal()
{
    return &m_signal;
}

template<typename type, TYPE_VISIBLE T>
int MainWidget<type, T>::getCurrentTab()
{
    int id = m_tabWidget->currentIndex();
    int i{};
    for (int index = 0; index < id; ++i) {
        if (!m_tabs[i].deleteTab)
            ++index;
    }

    return i;
}

template<typename type, TYPE_VISIBLE T>
void MainWidget<type, T>::updateGridValues(int idTab)
{
    // Update grid values and its positions
    std::pair<std::vector<int>, std::vector<int>> axesValue = m_tabs[idTab].OGLWidget->getGridValues();

    std::pair<std::vector<double>, std::vector<double>> Values = m_tabs[idTab].OGLWidget->getValues();

    const auto &childrenY = m_tabs[idTab].XAxis->children();

    for (QObject *child : childrenY) {
        QLabel *label = qobject_cast<QLabel *>(child);
        if (label)
            delete label;
    }

    const auto &childrenX = m_tabs[idTab].YAxis->children();

    for (QObject *child : childrenX) {
        QLabel *label = qobject_cast<QLabel *>(child);
        if (label)
            delete label;
    }

    QRgb colorText = m_tabs[idTab].colorText;

    for (size_t i = 0; i < axesValue.first.size() - 1; ++i) {
        QLabel *label = new QLabel(QString::number(Values.first[i]), m_tabs[idTab].XAxis);
        label->move(axesValue.first[i] - 10, -2);
        label->setStyleSheet("color: " + convertColorName(colorText) + ";");
        label->show();
    }

    for (size_t i = 0; i < axesValue.second.size() - 1; ++i) {
        QLabel *label = new QLabel(QString::number(Values.second[i], 'g', 3), m_tabs[idTab].YAxis);
        label->setFixedHeight(16);
        label->move(0, axesValue.second[i] - 12);
        label->setStyleSheet("color: " + convertColorName(colorText) + ";");
        label->show();
    }

    QLabel *cursorValueXLable = new QLabel(QString::number(Values.first.back()), m_tabs[idTab].XAxis);
    cursorValueXLable->move(axesValue.first.back() - 8, -2);
    cursorValueXLable->setStyleSheet("background-color: " + convertColorName(m_tabs[idTab].colorBackCursor) + ";"
                                     "color: " + convertColorName(colorText) + ";");
    cursorValueXLable->show();

    QLabel *cursorValueYLable = new QLabel(QString::number(Values.second.back()), m_tabs[idTab].YAxis);
    cursorValueYLable->setFixedHeight(16);
    cursorValueYLable->move(0, axesValue.second.back() - 12);
    cursorValueYLable->setStyleSheet("background-color: " + convertColorName(m_tabs[idTab].colorBackCursor) + ";"
                                     "color: " + convertColorName(colorText) + ";");
    cursorValueYLable->show();

    // QLabel *nameAxisXLable = new QLabel(m_tabs[idTab].axesName.first, m_tabs[idTab].XAxis);
    // nameAxisXLable->setFixedWidth(35);
    // nameAxisXLable->move(m_tabs[idTab].OGLWidget->width() / 2, 16);
    // nameAxisXLable->setStyleSheet("color: " + convertColorName(colorText) + ";");
    // nameAxisXLable->show();

    // QLabel *nameAxisYLable = new QLabel(m_tabs[idTab].axesName.second, m_tabs[idTab].YAxis);
    // nameAxisYLable->setFixedHeight(16);
    // nameAxisYLable->move(0, m_tabs[idTab].OGLWidget->height() / 2);
    // nameAxisYLable->setStyleSheet("color: " + convertColorName(colorText) + ";");
    // nameAxisYLable->show();
}

template<typename type, TYPE_VISIBLE T>
inline QString MainWidget<type, T>::convertColorName(QRgb color)
{
    return QString("rgb(%1, %2, %3)").arg(qRed(color)).arg(qGreen(color)).arg(qBlue(color));
}

#endif // MAIN_WIDGET_H
