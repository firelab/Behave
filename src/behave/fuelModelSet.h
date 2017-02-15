/******************************************************************************
*
* Project:  CodeBlocks
* Purpose:  Class for handling values associated with fuel models used in the
*           Rothermel model
* Author:   William Chatham <wchatham@fs.fed.us>
* Credits:  Some of the code in the corresponding cpp file is, in part or in
*           whole, from BehavePlus5 source originally authored by Collin D.
*           Bevins and is used with or without modification.
*
*******************************************************************************
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
******************************************************************************/

#ifndef FUELMODELSET_H
#define FUELMODELSET_H

#include "behaveUnits.h"
#include <string>
#include <vector>

// TODO: Add in a std::map to map fuel codes to the respective fuel model number in FuelModelArray -WMC 02/2017

class FuelModelSet
{
public:
    FuelModelSet();
    FuelModelSet& operator=(const FuelModelSet& rhs);
    FuelModelSet(const FuelModelSet& rhs);
    ~FuelModelSet();
   
    bool setCustomFuelModel(int fuelModelNumberIn, std::string code, std::string name,
        double fuelBedDepth, double moistureOfExtinctionDead, double heatOfCombustionDead, double heatOfCombustionLive,
        double fuelLoadOneHour, double fuelLoadTenHour, double fuelLoadHundredHour, double fuelLoadLiveHerbaceous,
        double fuelLoadLiveWoody, double savrOneHour, double savrLiveHerbaceous, double savrLiveWoody,
        bool isDynamic);
    bool clearCustomFuelModel(int fuelModelNumber);

    std::string getFuelCode(int fuelModelNumber) const;
    std::string getFuelName(int fuelModelNumber) const;
    double getFuelbedDepth(int fuelModelNumber) const;
    double getMoistureOfExtinctionDead(int fuelModelNumber) const;;
    double getHeatOfCombustionDead(int fuelModelNumber) const;
    double getHeatOfCombustionLive(int fuelModelNumber) const;
    double getFuelLoadOneHour(int fuelModelNumber) const;
    double getFuelLoadTenHour(int fuelModelNumber) const;
    double getFuelLoadHundredHour(int fuelModelNumber) const;
    double getFuelLoadLiveHerbaceous(int fuelModelNumber) const;
    double getFuelLoadLiveWoody(int fuelModelNumber) const;
    double getSavrOneHour(int fuelModelNumber) const;
    double getSavrLiveHerbaceous(int fuelModelNumber) const;
    double getSavrLiveWoody(int fuelModelNumber) const;
    bool getIsDynamic(int fuelModelNumber) const;
    bool isFuelModelDefined(int fuelModelNumber) const;

private:
    void memberwiseCopyAssignment(const FuelModelSet& rhs);
    void initializeSingleFuelModelRecord(int fuelModelNumber);
    void initializeAllFuelModelRecords();
    void populateFuelModels();
    void markAsReservedModel(int fuelModelNumber);
    void setFuelModelRecord(int fuelModelCodeIn, std::string code, std::string name,
        double fuelBedDepth, double moistureOfExtinctionDead, double heatOfCombustionDead, double heatOfCombustionLive,
        double fuelLoadOneHour, double fuelLoadTenHour, double fuelLoadHundredHour, double fuelLoadLiveHerbaceous,
        double fuelLoadLiveWoody, double savrOneHourFuel, double savrLiveHerbaceous, double savrLiveWoody,
        bool isDynamic, bool isReserved);

    struct FuelModelRecord
    {
        int fuelModelNumber_;               // Standard ID number for fuel model 
        std::string code_;                  // Fuel model code, usually 2 letters followed by number,(e.g., "GR1")
        std::string name_;                  // Fuel model name, (e.g., "Humid Climate Grass")
        double fuelbedDepth_;               // Fuelbed depth in feet
        double moistureOfExtinctionDead_;   // Dead fuel extinction moisture content (fraction)
        double heatOfCombustionDead_;       // Dead fuel heat of combustion (Btu/lb)
        double heatOfCombustionLive_;       // Live fuel heat of combustion (Btu/lb)
        double fuelLoadOneHour_;            // Dead 1 hour fuel loading (lb/ft^2)
        double fuelLoadTenHour_;            // Dead 10 hour fuel loading (lb/ft^2)
        double fuelLoadHundredHour_;        // Dead 100 hour fuel loading (lb/ft^2)
        double fuelLoadLiveHerbaceous_;     // Live herb fuel loading (lb/ft^2)
        double fuelLoadLiveWoody_;          // Live wood fuel loading (lb/ft^2)
        double savrOneHour_;                // Dead 1-h fuel surface area to volume ratio (ft^2/ft^3)
        double savrLiveHerbaceous_;         // Live herb surface area to volume ratio (ft^2/ft^3)
        double savrLiveWoody_;              // Live wood surface area to volume ratio (ft^2/ft^3)
        bool isDynamic_;                    // If true, the fuel model is dynamic
        bool isReserved_;                   // If true, record cannot be used for custom fuel model
        bool isDefined_;                    // If true, record has been populated with values for its fields
    };

    std::vector<FuelModelRecord> FuelModelArray;

};

#endif // FUELMODELSET_H
