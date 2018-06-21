#pragma once

#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>

class qssUseClass
{
public:
	qssUseClass(void);
	~qssUseClass(void);
};

class myPushButton : public QPushButton
{
	Q_OBJECT
	Q_PROPERTY(QString teacherName READ teacherName WRITE setTeacherName NOTIFY teacherNameChange);
public:
	myPushButton(QWidget* par = nullptr);

	QString teacherName();
	void setTeacherName(const QString& name);

signals:
	void teacherNameChange(const QString& name);

private:
	QString m_teacherName;


};

