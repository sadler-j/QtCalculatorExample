#ifndef EVALUATIONSETTINGS_H
#define EVALUATIONSETTINGS_H

namespace Compute
{
class EvaluationSettings
{
public:
    bool IsRadians() const;

    void IsRadians(bool radians);

private:
    bool radians {true};
};
}

#endif // EVALUATIONSETTINGS_H
