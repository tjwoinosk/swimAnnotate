set(WX_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets")

# wxWidgets config
set(wxBUILD_SHARED OFF)
set(wxUSE_OPENGL OFF)
set(wxUSE_WEBVIEW OFF)
set(wxUSE_MEDIACTRL OFF)
set(wxUSE_RIBBON OFF)
set(wxUSE_STC OFF)
set(wxUSE_PROPGRID OFF)
# Add as subproject
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets" EXCLUDE_FROM_ALL)
# Meta target for easy use wxWidgets
add_library(wx INTERFACE)
if(wxBUILD_SHARED)
	target_compile_definitions(wx
		INTERFACE
			-DWXUSINGDLL
	)
endif()
target_link_libraries(wx
	INTERFACE
		wxbase
		wxcore
		wxadv
		wxhtml
		wxnet
		wxqa
		wxaui
		wxrichtext
		wxxml
		wxxrc
)
if(wxUSE_PROPGRID)
	target_link_libraries(wx
		INTERFACE
			wxpropgrid
	)
endif()
if(wxUSE_STC)
	target_link_libraries(wx
		INTERFACE
			wxstc
	)
endif()
if(wxUSE_RIBBON)
	target_link_libraries(wx
		INTERFACE
			wxribbon
	)
endif()
if(wxUSE_WEBVIEW)
	target_link_libraries(wx
		INTERFACE
			wxwebview
	)
endif()
if(wxUSE_MEDIACTRL)
	target_link_libraries(wx
		INTERFACE
			wxmedia
	)
endif()
if(wxUSE_OPENGL)
	target_link_libraries(wx
		INTERFACE
			wxgl
	)
endif()
add_library(third::wx ALIAS wx)

