class ManagedColor : QObject
{
%TypeHeaderCode
#include "ManagedColor.h"
%End
    ManagedColor(const Palette & __0);
public:
    ManagedColor(const QString &colorModel, const QString &colorDepth, const QString &colorProfile, QObject *parent = 0);
    bool operator==(const ManagedColor &other) const;
    QColor colorForCanvas(Canvas *canvas) const;
    QString colorDepth() const;
    QString colorModel() const;
    QString colorProfile() const;
    bool setColorProfile(const QString &colorProfile);
    bool setColorSpace(const QString &colorModel, const QString &colorDepth, const QString &colorProfile);
    QVector<float> components() const;
    void setComponents(const QVector<float> &values);
    QString toXML() const;
    void fromXML(const QString &xml);
    QString toQString();

private:
};
