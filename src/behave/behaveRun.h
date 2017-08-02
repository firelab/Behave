/******************************************************************************
*
* Project:  CodeBlocks
* Purpose:  Interface for Behave application based on the Facade OOP Design 
*           Pattern used to tie together the modules and objects used by Behave
* Author:   William Chatham <wchatham@fs.fed.us>
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

// TODO: Need to revisit how the Two Fuel Models module is organized and handled - WMC 02/2016

#ifndef BEHAVERUN_H
#define BEHAVERUN_H

#include "behaveUnits.h"
#include "crown.h"
#include "ignite.h"
#include "spot.h"
#include "surface.h"

class FuelModels;

class BehaveRun
{
public:
    BehaveRun() = delete; // There is no default constructor
    explicit BehaveRun(FuelModelSet& fuelModelSet);
    
    BehaveRun(const BehaveRun& rhs);
    BehaveRun& operator=(const BehaveRun& rhs);
    ~BehaveRun();

    // FuelModelSet Methods
    bool isFuelModelDefined(int fuelModelNumber) const;
	double getFuelLoadOneHour(int fuelModelNumber) const;
	double getFuelLoadTenHour(int fuelModelNumber) const;
	double getFuelLoadHundredHour(int fuelModelNumber) const;
	double getFuelLoadLiveHerbaceous(int fuelModelNumber) const;
	double getFuelLoadLiveWoody(int fuelModelNumber) const;

    void setFuelModelSet(FuelModelSet& fuelModelSet);

 // SURFACE Module
Surface surface;

// CROWN Module
Crown crown;

// SPOT Module
Spot spot;

//  Ignite Module
Ignite ignite;

private:
    void memberwiseCopyAssignment(const BehaveRun& rhs);

    // Fuel model set (orginal 13, 40 and custom)
    FuelModelSet* fuelModelSet_;
};

#endif //BEHAVERUN_H
