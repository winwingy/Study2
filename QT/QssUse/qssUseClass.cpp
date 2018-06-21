#include "qssUseClass.h"


qssUseClass::qssUseClass(void)
{
}


qssUseClass::~qssUseClass(void)
{
}

myPushButton::myPushButton(QWidget* par /*= nullptr*/)
	: QPushButton(par)
{

}

QString myPushButton::teacherName()
{
	return m_teacherName;
}

void myPushButton::setTeacherName(const QString& name)
{
	m_teacherName = name;
	emit teacherNameChange(m_teacherName);
}
