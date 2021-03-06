/*!
 * \copy
 *     Copyright (c)  2013, Cisco Systems
 *     All rights reserved.
 *
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions
 *     are met:
 *
 *        * Redistributions of source code must retain the above copyright
 *          notice, this list of conditions and the following disclaimer.
 *
 *        * Redistributions in binary form must reproduce the above copyright
 *          notice, this list of conditions and the following disclaimer in
 *          the documentation and/or other materials provided with the
 *          distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *     "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *     FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *     COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *     BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *     CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *     LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *     ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *     POSSIBILITY OF SUCH DAMAGE.
 *
 */

//nal_prefix.h	-	definitions for NAL Unit Header(/Ext) and PrefixNALUnit
#ifndef WELS_NAL_UNIT_PREFIX_H__
#define WELS_NAL_UNIT_PREFIX_H__

#include "typedefs.h"
#include "wels_common_basis.h"
#include "slice.h"

namespace WelsDec {

///////////////////////////////////NAL Unit prefix/headers///////////////////////////////////

/* NAL Unix Header in AVC, refer to Page 56 in JVT X201wcm */
typedef struct TagNalUnitHeader {
  uint8_t		    uiForbiddenZeroBit;
  uint8_t		    uiNalRefIdc;
  ENalUnitType    eNalUnitType;
  uint8_t		    uiReservedOneByte;		// only padding usage
} SNalUnitHeader, *PNalUnitHeader;

/* NAL Unit Header in scalable extension syntax, refer to Page 390 in JVT X201wcm */
typedef struct TagNalUnitHeaderExt {
  SNalUnitHeader	sNalUnitHeader;

//	uint8_t		reserved_one_bit;
  bool_t		bIdrFlag;
  uint8_t		uiPriorityId;
  int8_t		iNoInterLayerPredFlag;	// change as int8_t to support 3 values probably in encoder
  uint8_t		uiDependencyId;

  uint8_t		uiQualityId;
  uint8_t		uiTemporalId;
  bool_t		bUseRefBasePicFlag;
  bool_t		bDiscardableFlag;

  bool_t		bOutputFlag;
  uint8_t		uiReservedThree2Bits;
  // Derived variable(s)
  uint8_t		uiLayerDqId;
  bool_t		bNalExtFlag;
} SNalUnitHeaderExt, *PNalUnitHeaderExt;

/* Prefix NAL Unix syntax, refer to Page 392 in JVT X201wcm */
typedef struct TagPrefixNalUnit {
  SRefBasePicMarking	sRefPicBaseMarking;
  bool_t		bStoreRefBasePicFlag;
  bool_t		bPrefixNalUnitAdditionalExtFlag;
  bool_t		bPrefixNalUnitExtFlag;
} SPrefixNalUnit, *PPrefixNalUnit;

} // namespace WelsDec

#endif//WELS_NAL_UNIT_PREFIX_H__
