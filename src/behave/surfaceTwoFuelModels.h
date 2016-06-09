/******************************************************************************
*
* Project:  CodeBlocks
* Purpose:  Class for calculating the combined fire behavior characteristics of 
*           two different fuel models
* Author:   William Chatham <wchatham@fs.fed.us>
* Credits:  Some portions of code in this file are, in part or in whole, from
*           BehavePlus5 source originally authored by Collin D. Bevins and
*           Mark Finney, and is used with or without modification.
*
******************************************************************************
*
* THIS SOFTWARE WAS DEVELOPED AT THE ROCKY MOUNTAIN RESEARCH STATION (RMRS)
* MISSOULA FIRE SCIENCES LABORATORY BY EMPLOYEES OF THE FEDERAL GOVERNMENT
* IN THE COURSE OF THEIR OFFICIAL DUTIES. PURSUANT TO TITLE 17 SECTION 105
* OF THE UNITED STATES CODE, THIS SOFTWARE IS NOT SUBJECT TO COPYRIGHT
* PROTECTION AND IS IN THE PUBLIC DOMAIN. RMRS MISSOULA FIRE SCIENCES
* LABORATORY ASSUMES NO RESPONSIBILITY WHATSOEVER FOR ITS USE BY OTHER
* PARTIES,  AND MAKES NO GUARANTEES, EXPRESSED OR IMPLIED, ABOUT ITS QUALITY,
* RELIABILITY, OR ANY OTHER CHARACTERISTIC.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#ifndef SURFACETWOFUELMODELS_HEADER
#define SURFACETWOFUELMODELS_HEADER

#include "surfaceEnums.h"

class SurfaceInputs;
class SurfaceFuelbedIntermediates;
class SurfaceFireSpread;

class SurfaceTwoFuelModels
{
public:
    SurfaceTwoFuelModels(SurfaceInputs& surfaceInputs, SurfaceFireSpread& surfaceFireSpread);
    void calculateWeightedSpreadRate(bool hasDirectionOfInterest = false, double directionOfInterest = -1);

    //public getters
    bool getWindLimitExceeded() const;
    double getReactionIntensity() const;
    double getSpreadRate() const;
    double getDirectionOfMaxSpread() const;
    double getEffectiveWind() const;
    double getFuelbedDepth() const;
    double getHeatPerUnitArea() const;
    double getMidFlameWindSpeed() const;
    double getWindSpeedLimit() const;
    double WindAdjustmentFactor() const;
    double getFireLineIntensity() const;
    double getflameLength() const;
    double getFireLengthToWidthRatio() const;

private:
  
    SurfaceInputs* surfaceInputs_;
    SurfaceFireSpread* surfaceFireSpread_;

    double surfaceFireExpectedSpreadRate(double *ros, double *coverage, int fuels,
        double lbRatio, int samples, int depth, int laterals);
    void calculateFireOutputsForEachModel(bool hasDirectionOfInterest = false, double directionOfInterest = -1);
    void calculateSpreadRateBasedOnMethod();

    // Member arrays
    int fuelModelNumber_[TwoFuelModels::NUMBER_OF_MODELS];                      // fuel model number
    double coverageForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];              // percent coverage of fuel model
    double rosForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];                   // rate of spread
    double firelineIntensityForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];     // fireline intensity
    double maxFlameLengthForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];        // flame length in direction of max spread
    double flameLengthForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];           // flame length
    double fuelbedDepthForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];          // fuel bed depth in feet
    double effectiveWindSpeedForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];    // effective wind speed
    double lengthToWidthRatioForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];    // fire length-to-width ratio
    double reactionIntensityForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];     // reaction intensity, 
    double heatPerUnitAreaForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];       // heat per unit area
    double dirMaxSpreadForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];          // direction of max spread
    double windAdjustmentFactorForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];  // wind adjustment factor
    double midFlameWindSpeedForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];     // wind speed at midflame
    double windSpeedLimitForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];        // wind speed limit
    bool windLimitExceededForFuelModel_[TwoFuelModels::NUMBER_OF_MODELS];       // wind speed exceeded flag

    // Member variables
    bool windLimitExceeded_;        // (flag)
    double reactionIntensity_;      // (Btu / ft2 / min)
    double spreadRate_;             // (ft / min)
    double directionOfMaxSpread_;   // (clockwise from upslope or north)
    double effectiveWind_;          // (mi / h)
    double fuelbedDepth_;           // (ft)
    double heatPerUnitArea_;        // (Btu / ft2)
    double midFlameWindSpeed_;
    double windSpeedLimit_;         // (mi / h)
    double windAdjustmentFactor_;
    double fireLineIntensity_;      // (Btu / ft / s)
    double flameLength_;            // (ft)
    double maxFlameLength_;         // flame length in direction of maximum spread (ft)
    double fireLengthToWidthRatio_;
};

#endif //SURFACETWOFUELMODELS_HEADER
