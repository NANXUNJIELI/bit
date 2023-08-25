#ifndef TABLE_DEFINS_H
#define TABLE_DEFINS_H

#include <QString>
#include <QVariant>

#define SUPPORT_C11 0

namespace Table
{
	enum TABLE_SORT_MODE
	{
		ASCENDING,
		DESCENDING
	};

	Q_DECLARE_FLAGS(TableSort, TABLE_SORT_MODE)
	Q_DECLARE_OPERATORS_FOR_FLAGS(TableSort)
};

namespace UserOperate
{
	const int OPERATE_EDIT = 1;
	const int OPERATE_DELETE = 2;
    const int OPERATE_BACK = 3;

    const int OPERATE_FORBIDDEN = 4;
    const int OPERATE_ACTIVATE = 5;
    const int OPERATE_LOG = 6;


	const QString OPERATE_EDIT_TEXT = QString::fromLocal8Bit("�༭");
    const QString OPERATE_DELETE_TEXT = QString::fromLocal8Bit("ɾ��");
	const QString OPERATE_BACK_TEXT = QString::fromLocal8Bit("�һ�");

	const QString OPERATE_FORBIDDEN_TEXT = QString::fromLocal8Bit("����");
	const QString OPERATE_ACTIVATE_TEXT = QString::fromLocal8Bit("����");
	const QString OPERATE_LOG_TEXT = QString::fromLocal8Bit("��־����");

#if SUPPORT_C11	//�Ͱ汾�ı�������֧�ֳ�ʼ���б�ֱ�ӳ�ʼ������ʽ

    static QMap<int, QString> instance()
    {
        static QMap<int, QString> operate
        {
            {OPERATE_EDIT, OPERATE_EDIT_TEXT},
            {OPERATE_DELETE, OPERATE_DELETE_TEXT},
            {OPERATE_BACK, OPERATE_BACK_TEXT},
            {OPERATE_FORBIDDEN, OPERATE_FORBIDDEN_TEXT},
            {OPERATE_ACTIVATE, OPERATE_ACTIVATE_TEXT},
            {OPERATE_LOG, OPERATE_LOG_TEXT},
        };

        return operate;
    };

#else
    static QMap<int, QString> map;
    static QMap<int, QString>& instance()
    {
        return map;
    }

    class MapInsert
    {
    public:
        static void initOperate()
        {
            map.insert(OPERATE_EDIT, OPERATE_EDIT_TEXT);
            map.insert(OPERATE_DELETE, OPERATE_DELETE_TEXT);
            map.insert(OPERATE_BACK, OPERATE_BACK_TEXT);
            map.insert(OPERATE_FORBIDDEN, OPERATE_FORBIDDEN_TEXT);
            map.insert(OPERATE_ACTIVATE, OPERATE_ACTIVATE_TEXT);
            map.insert(OPERATE_LOG, OPERATE_LOG_TEXT);
        }
    };

#endif

	struct UserOperater
	{
		int row{ -1 };
		int column{ -1 };
		int type{ 0 };	//0 : �����list��ʾ����������У� 1 : ��ʾ����
        QVariant operate{ QVariant() };
		UserOperater() = default;
	};
}

#endif // TABLE_DEFINS_H
