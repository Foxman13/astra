#ifndef HAND_TYPES_H
#define HAND_TYPES_H

#include <SenseKit/sensekit_types.h>
#include <SenseKitUL/skul_ctypes.h>

#define SENSEKIT_HANDS_MAX_HAND_COUNT 20

typedef enum _sensekit_debug_hand_view_type {
    DEBUG_HAND_VIEW_DEPTH,
    DEBUG_HAND_VIEW_VELOCITY,
    DEBUG_HAND_VIEW_FILTEREDVELOCITY,
    DEBUG_HAND_VIEW_UPDATE_SEGMENTATION,
    DEBUG_HAND_VIEW_CREATE_SEGMENTATION,
    DEBUG_HAND_VIEW_UPDATE_SEARCHED,
    DEBUG_HAND_VIEW_CREATE_SEARCHED,
    DEBUG_HAND_VIEW_CREATE_SCORE,
    DEBUG_HAND_VIEW_UPDATE_SCORE,
    DEBUG_HAND_VIEW_HANDWINDOW,
    DEBUG_HAND_VIEW_DEPTH_MOD,
    DEBUG_HAND_VIEW_DEPTH_AVG,
} sensekit_debug_hand_view_type_t;

typedef enum _sensekit_handstatus {
    HAND_STATUS_NOTTRACKING,
    HAND_STATUS_CANDIDATE,
    HAND_STATUS_TRACKING,
    HAND_STATUS_LOST
} sensekit_handstatus_t;

typedef struct _sensekit_handpoint {
    int32_t trackingId;
    sensekit_handstatus_t status;
    sensekit_vector2i_t depthPosition;
    sensekit_vector3f_t worldPosition;
    sensekit_vector3f_t worldDeltaPosition;
} sensekit_handpoint_t;

typedef struct _sensekit_handframe* sensekit_handframe_t;
typedef sensekit_streamconnection_t sensekit_handstream_t;

typedef struct _sensekit_imageframe* sensekit_debug_handframe_t;
typedef sensekit_streamconnection_t sensekit_debug_handstream_t;

#endif // HAND_TYPES_H
