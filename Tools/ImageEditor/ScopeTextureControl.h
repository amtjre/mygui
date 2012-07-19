/*!
	@file
	@author		Albert Semenov
	@date		08/2010
*/

#ifndef _31513eda_9f1b_4986_a5a5_466942db581b_
#define _31513eda_9f1b_4986_a5a5_466942db581b_

#include "TextureToolControl.h"
#include "AreaSelectorControl.h"
#include "PositionSelectorBlackControl.h"
#include "Property.h"

namespace tools
{

	class ScopeTextureControl :
		public TextureToolControl,
		public sigslot::has_slots<>
	{
	public:
		ScopeTextureControl();
		virtual ~ScopeTextureControl();

		void setCoordValue(const MyGUI::IntCoord& _value);
		void clearCoordValue();

		typedef std::vector<MyGUI::IntCoord> VectorCoord;
		void setViewSelectors(const VectorCoord& _selectors);
		void clearViewSelectors();

		void clearAll();

		sigslot::signal1<const std::string&> eventChangeValue;

	protected:
		virtual void OnInitialise(Control* _parent, MyGUI::Widget* _place, const std::string& _layoutName);

		virtual void onMouseButtonClick(const MyGUI::IntPoint& _point);

		virtual void onChangeScale();
		virtual void onChangeActivate();

	private:
		void notifyChangeSelection();
		void notifyComboChangePosition(MyGUI::ComboBox* _sender, size_t _index);
		void notifyChangePosition(SelectorControl* _sender);

		void updateFromCoordValue();

		void CommandMoveLeft(const MyGUI::UString& _commandName, bool& _result);
		void CommandMoveRight(const MyGUI::UString& _commandName, bool& _result);
		void CommandMoveTop(const MyGUI::UString& _commandName, bool& _result);
		void CommandMoveBottom(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridMoveLeft(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridMoveRight(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridMoveTop(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridMoveBottom(const MyGUI::UString& _commandName, bool& _result);

		void CommandSizeLeft(const MyGUI::UString& _commandName, bool& _result);
		void CommandSizeRight(const MyGUI::UString& _commandName, bool& _result);
		void CommandSizeTop(const MyGUI::UString& _commandName, bool& _result);
		void CommandSizeBottom(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridSizeLeft(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridSizeRight(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridSizeTop(const MyGUI::UString& _commandName, bool& _result);
		void CommandGridSizeBottom(const MyGUI::UString& _commandName, bool& _result);

		void updateCaption();

		void setValue(const std::string& _value);

	private:
		AreaSelectorControl* mAreaSelectorControl;
		MyGUI::IntCoord mCoordValue;
		std::vector<PositionSelectorBlackControl*> mBlackSelectors;
	};

}

#endif
