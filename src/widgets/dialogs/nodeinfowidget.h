#ifndef NODEINFOWIDGET_H
#define NODEINFOWIDGET_H

#include <QWidget>

#include "notebook/node.h"

class QLineEdit;
class QLabel;
class QFormLayout;

namespace vnotex
{
    class Notebook;
    class NodeLabelWithUpButton;

    class NodeInfoWidget : public QWidget
    {
        Q_OBJECT
    public:
        enum Mode { Create, Edit };

        NodeInfoWidget(const Node *p_node, QWidget *p_parent = nullptr);

        NodeInfoWidget(const Node *p_parentNode,
                       Node::Type p_typeToCreate,
                       QWidget *p_parent = nullptr);

        QLineEdit *getNameLineEdit() const;

        QString getName() const;

        const Notebook *getNotebook() const;

        const Node *getParentNode() const;

    signals:
        void inputEdited();

    private:
        void setupUI(const Node *p_parentNode);

        void setupNameLineEdit(QWidget *p_parent);

        void setStateAccordingToModeAndNodeType(Node::Type p_type);

        void setNode(const Node *p_node);

        Mode m_mode;

        QFormLayout *m_mainLayout = nullptr;

        QLineEdit *m_nameLineEdit = nullptr;

        NodeLabelWithUpButton *m_parentNodeLabel = nullptr;

        QLabel *m_createdDateTimeLabel = nullptr;

        QLabel *m_modifiedDateTimeLabel = nullptr;

        const Node *m_node = nullptr;
    };
} // ns vnotex

#endif // NODEINFOWIDGET_H
