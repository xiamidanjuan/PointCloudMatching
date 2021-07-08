#ifndef HALCONVISUALIZE_H
#define HALCONVISUALIZE_H

#include "HalconCpp.h"
#include "HDevThread.h"
using namespace HalconCpp;

class HalconVisualize
{
public:
    HalconVisualize();
    // Chapter: Graphics / Output
    // Short Description: Compute the center of all given 3D object models.
    void get_object_models_center (HTuple hv_ObjectModel3DID, HTuple *hv_Center);
    // Chapter: Graphics / Output
    // Short Description: Interactively display 3D object models
    void visualize_object_model_3d (HTuple hv_WindowHandle, HTuple hv_ObjectModel3D,
        HTuple hv_CamParam, HTuple hv_PoseIn, HTuple hv_GenParamName, HTuple hv_GenParamValue,
        HTuple hv_Title, HTuple hv_Label, HTuple hv_Information, HTuple *hv_PoseOut);
    bool flag_extern = false;

private:
    HTuple  gIsSinglePose;
    HTuple  gTerminationButtonLabel;
    HTuple  gInfoDecor;
    HTuple  gInfoPos;
    HTuple  gTitlePos;
    HTuple  gTitleDecor;
    HTuple  gAlphaDeselected;
    HTuple  gDispObjOffset;
    HTuple  gLabelsDecor;
    HTuple  gUsesOpenGL;
    HTuple ExpGetGlobalVar_gIsSinglePose(void)
    {
      return gIsSinglePose;
    }
    void ExpSetGlobalVar_gIsSinglePose(HTuple val)
    {
      gIsSinglePose = val;
    }

    HTuple ExpGetGlobalVar_gTerminationButtonLabel(void)
    {
      return gTerminationButtonLabel;
    }
    void ExpSetGlobalVar_gTerminationButtonLabel(HTuple val)
    {
      gTerminationButtonLabel = val;
    }

    HTuple ExpGetGlobalVar_gInfoDecor(void)
    {
      return gInfoDecor;
    }
    void ExpSetGlobalVar_gInfoDecor(HTuple val)
    {
      gInfoDecor = val;
    }

    HTuple ExpGetGlobalVar_gInfoPos(void)
    {
      return gInfoPos;
    }
    void ExpSetGlobalVar_gInfoPos(HTuple val)
    {
      gInfoPos = val;
    }

    HTuple ExpGetGlobalVar_gTitlePos(void)
    {
      return gTitlePos;
    }
    void ExpSetGlobalVar_gTitlePos(HTuple val)
    {
      gTitlePos = val;
    }

    HTuple ExpGetGlobalVar_gTitleDecor(void)
    {
      return gTitleDecor;
    }
    void ExpSetGlobalVar_gTitleDecor(HTuple val)
    {
      gTitleDecor = val;
    }

    HTuple ExpGetGlobalVar_gAlphaDeselected(void)
    {
      return gAlphaDeselected;
    }
    void ExpSetGlobalVar_gAlphaDeselected(HTuple val)
    {
      gAlphaDeselected = val;
    }

    HTuple ExpGetGlobalVar_gDispObjOffset(void)
    {
      return gDispObjOffset;
    }
    void ExpSetGlobalVar_gDispObjOffset(HTuple val)
    {
      gDispObjOffset = val;
    }

    HTuple ExpGetGlobalVar_gLabelsDecor(void)
    {
      return gLabelsDecor;
    }
    void ExpSetGlobalVar_gLabelsDecor(HTuple val)
    {
      gLabelsDecor = val;
    }

    HTuple ExpGetGlobalVar_gUsesOpenGL(void)
    {
      return gUsesOpenGL;
    }
    void ExpSetGlobalVar_gUsesOpenGL(HTuple val)
    {
      gUsesOpenGL = val;
    }

    // Procedure declarations
    // External procedures
    // Chapter: Graphics / Output
    // Short Description: Reflect the pose change that was introduced by the user by moving the mouse
    void analyze_graph_event (HObject ho_BackgroundImage, HTuple hv_MouseMapping, HTuple hv_Button,
        HTuple hv_Row, HTuple hv_Column, HTuple hv_WindowHandle, HTuple hv_WindowHandleBuffer,
        HTuple hv_VirtualTrackball, HTuple hv_TrackballSize, HTuple hv_SelectedObjectIn,
        HTuple hv_Scene3D, HTuple hv_AlphaOrig, HTuple hv_ObjectModel3DID, HTuple hv_CamParam,
        HTuple hv_Labels, HTuple hv_Title, HTuple hv_Information, HTuple hv_GenParamName,
        HTuple hv_GenParamValue, HTuple hv_PosesIn, HTuple hv_ButtonHoldIn, HTuple hv_TBCenter,
        HTuple hv_TBSize, HTuple hv_WindowCenteredRotationlIn, HTuple hv_MaxNumModels,
        HTuple *hv_PosesOut, HTuple *hv_SelectedObjectOut, HTuple *hv_ButtonHoldOut,
        HTuple *hv_WindowCenteredRotationOut);
    // Chapter: Graphics / Parameters
    void color_string_to_rgb (HTuple hv_Color, HTuple *hv_RGB);
    // Chapter: Graphics / Output
    // Short Description: Determine the optimum distance of the object to obtain a reasonable visualization
    void determine_optimum_pose_distance (HTuple hv_ObjectModel3DID, HTuple hv_CamParam,
        HTuple hv_ImageCoverage, HTuple hv_PoseIn, HTuple *hv_PoseOut);
    // Chapter: Develop
    // Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'.
    void dev_update_off ();
    // Chapter: Graphics / Output
    // Short Description: Displays a continue button.
    void disp_continue_button (HTuple hv_WindowHandle);
    // Chapter: Graphics / Text
    // Short Description: This procedure writes one or multiple text messages.
    void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
        HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
    // Chapter: Graphics / Output
    // Short Description: Can replace disp_object_model_3d if there is no OpenGL available.
    void disp_object_model_no_opengl (HObject *ho_ModelContours, HTuple hv_ObjectModel3DID,
        HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple hv_WindowHandleBuffer,
        HTuple hv_CamParam, HTuple hv_PosesOut);
    // Chapter: Graphics / Text
    // Short Description: This procedure writes a text message.
    void disp_text_button (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
        HTuple hv_Row, HTuple hv_Column, HTuple hv_TextColor, HTuple hv_ButtonColor);
    // Chapter: Graphics / Output
    void disp_title_and_information (HTuple hv_WindowHandle, HTuple hv_Title, HTuple hv_Information);
    // Chapter: Graphics / Output
    // Short Description: Renders 3D object models in a buffer window.
    void dump_image_output (HObject ho_BackgroundImage, HTuple hv_WindowHandleBuffer,
        HTuple hv_Scene3D, HTuple hv_AlphaOrig, HTuple hv_ObjectModel3DID, HTuple hv_GenParamName,
        HTuple hv_GenParamValue, HTuple hv_CamParam, HTuple hv_Poses, HTuple hv_ColorImage,
        HTuple hv_Title, HTuple hv_Information, HTuple hv_Labels, HTuple hv_VisualizeTrackball,
        HTuple hv_DisplayContinueButton, HTuple hv_TrackballCenterRow, HTuple hv_TrackballCenterCol,
        HTuple hv_TrackballRadiusPixel, HTuple hv_SelectedObject, HTuple hv_VisualizeRotationCenter,
        HTuple hv_RotationCenter);
    // Chapter: Calibration / Camera Parameters
    // Short Description: Generate a camera parameter tuple for an area scan camera with distortions modeled by the division model.
    void gen_cam_par_area_scan_division (HTuple hv_Focus, HTuple hv_Kappa, HTuple hv_Sx,
        HTuple hv_Sy, HTuple hv_Cx, HTuple hv_Cy, HTuple hv_ImageWidth, HTuple hv_ImageHeight,
        HTuple *hv_CameraParam);
    // Chapter: Calibration / Camera Parameters
    // Short Description: Get the value of a specified camera parameter from the camera parameter tuple.
    void get_cam_par_data (HTuple hv_CameraParam, HTuple hv_ParamName, HTuple *hv_ParamValue);
    // Chapter: Calibration / Camera Parameters
    // Short Description: Get the names of the parameters in a camera parameter tuple.
    void get_cam_par_names (HTuple hv_CameraParam, HTuple *hv_CameraType, HTuple *hv_ParamNames);
    // Chapter: Graphics / Output
    // Short Description: Get the center of the virtual trackback that is used to move the camera.
    void get_trackball_center (HTuple hv_SelectedObject, HTuple hv_TrackballRadiusPixel,
        HTuple hv_ObjectModel3D, HTuple hv_Poses, HTuple *hv_TBCenter, HTuple *hv_TBSize);
    // Chapter: Graphics / Output
    // Short Description: Get the center of the virtual trackback that is used to move the camera (version for inspection_mode = 'surface').
    void get_trackball_center_fixed (HTuple hv_SelectedObject, HTuple hv_TrackballCenterRow,
        HTuple hv_TrackballCenterCol, HTuple hv_TrackballRadiusPixel, HTuple hv_Scene3D,
        HTuple hv_ObjectModel3DID, HTuple hv_Poses, HTuple hv_WindowHandleBuffer, HTuple hv_CamParam,
        HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple *hv_TBCenter, HTuple *hv_TBSize);
    // Chapter: Graphics / Output
    // Short Description: Get string extends of several lines.
    void max_line_width (HTuple hv_WindowHandle, HTuple hv_Lines, HTuple *hv_MaxWidth);
    // Chapter: Graphics / Output
    // Short Description: Project an image point onto the trackball
    void project_point_on_trackball (HTuple hv_X, HTuple hv_Y, HTuple hv_VirtualTrackball,
        HTuple hv_TrackballSize, HTuple *hv_V);
    // Chapter: Calibration / Camera Parameters
    // Short Description: Set the value of a specified camera parameter in the camera parameter tuple.
    void set_cam_par_data (HTuple hv_CameraParamIn, HTuple hv_ParamName, HTuple hv_ParamValue,
        HTuple *hv_CameraParamOut);
    // Chapter: Graphics / Text
    // Short Description: Set font independent of OS
    void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
        HTuple hv_Slant);
    // Chapter: Graphics / Output
    // Short Description: Compute the 3D rotation from the mouse movement
    void trackball (HTuple hv_MX1, HTuple hv_MY1, HTuple hv_MX2, HTuple hv_MY2, HTuple hv_VirtualTrackball,
        HTuple hv_TrackballSize, HTuple hv_SensFactor, HTuple *hv_QuatRotation);
    // Chapter: Tuple / Arithmetic
    // Short Description: Calculates the cross product of two vectors of length 3.
    void tuple_vector_cross_product (HTuple hv_V1, HTuple hv_V2, HTuple *hv_VC);
};

#endif // HALCONVISUALIZE_H
