#include "evaluationsettings.h"

using namespace Compute;

bool EvaluationSettings::IsRadians() const
{
    return radians;
}

void EvaluationSettings::IsRadians(bool radians)
{
    this->radians = radians;
}
