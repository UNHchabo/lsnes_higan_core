struct Font;
struct Window;
struct Menu;
struct Sizable;
struct Layout;
struct Widget;

struct pFont;
struct pObject;
struct pOS;
struct pTimer;
struct pWindow;
struct pAction;
struct pMenu;
struct pSeparator;
struct pItem;
struct pCheckItem;
struct pRadioItem;
struct pSizable;
struct pLayout;
struct pWidget;
struct pButton;
struct pCanvas;
struct pCheckBox;
struct pComboBox;
struct pHexEdit;
struct pHorizontalScrollBar;
struct pHorizontalSlider;
struct pLabel;
struct pLineEdit;
struct pListView;
struct pProgressBar;
struct pRadioBox;
struct pTextEdit;
struct pVerticalScrollBar;
struct pVerticalSlider;
struct pViewport;

enum : unsigned {
  MaximumSize = ~0u,
  MinimumSize =  0u,
};

struct Color {
  uint8_t red, green, blue, alpha;
  inline Color() : red(0), green(0), blue(0), alpha(255) {}
  inline Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) : red(red), green(green), blue(blue), alpha(alpha) {}
};

struct Position {
  signed x, y;
  inline Position() : x(0), y(0) {}
  inline Position(signed x, signed y) : x(x), y(y) {}
};

struct Size {
  unsigned width, height;
  inline Size() : width(0), height(0) {}
  inline Size(unsigned width, unsigned height) : width(width), height(height) {}
};

struct Geometry {
  signed x, y;
  unsigned width, height;
  Position position() const;
  Size size() const;
  nall::string text() const;
  inline Geometry() : x(0), y(0), width(0), height(0) {}
  inline Geometry(signed x, signed y, unsigned width, unsigned height) : x(x), y(y), width(width), height(height) {}
  Geometry(const nall::string &text);
};

enum class Orientation : unsigned { Horizontal, Vertical };

struct Font {
  nall::string description;
  Geometry geometry(const nall::string &text);
  Font(const nall::string &description = "");
};

struct Desktop {
  static Size size();
  static Geometry workspace();
  Desktop() = delete;
};

struct Keyboard {
  #include "keyboard.hpp"
  static bool pressed(Scancode scancode);
  static bool released(Scancode scancode);
  static nall::array<bool> state();
  Keyboard() = delete;
};

struct Mouse {
  enum class Button : unsigned { Left, Middle, Right };
  static Position position();
  static bool pressed(Button);
  static bool released(Button);
  Mouse() = delete;
};

struct DialogWindow {
  template<typename... Args> static nall::string fileOpen(Window &parent, const nall::string &path, const Args&... args) { return fileOpen_(parent, path, { args... }); }
  template<typename... Args> static nall::string fileSave(Window &parent, const nall::string &path, const Args&... args) { return fileSave_(parent, path, { args... }); }
  static nall::string folderSelect(Window &parent, const nall::string &path);
  DialogWindow() = delete;

private:
  static nall::string fileOpen_(Window &parent, const nall::string &path, const nall::lstring& filter);
  static nall::string fileSave_(Window &parent, const nall::string &path, const nall::lstring& filter);
};

struct MessageWindow {
  enum class Buttons : unsigned {
    Ok,
    OkCancel,
    YesNo,
  };

  enum class Response : unsigned {
    Ok,
    Cancel,
    Yes,
    No,
  };

  static Response information(Window &parent, const nall::string &text, Buttons = Buttons::Ok);
  static Response question(Window &parent, const nall::string &text, Buttons = Buttons::YesNo);
  static Response warning(Window &parent, const nall::string &text, Buttons = Buttons::Ok);
  static Response critical(Window &parent, const nall::string &text, Buttons = Buttons::Ok);
  MessageWindow() = delete;
};

struct Object {
  Object(pObject &p);
  Object& operator=(const Object&) = delete;
  Object(const Object&) = delete;
  virtual ~Object();
  pObject &p;
};

struct OS : Object {
  static void main();
  static bool pendingEvents();
  static void processEvents();
  static void quit();

  OS();
  static void initialize();
};

struct Timer : private nall::base_from_member<pTimer&>, Object {
  nall::function<void ()> onTimeout;

  void setEnabled(bool enabled = true);
  void setInterval(unsigned milliseconds);

  Timer();
  ~Timer();
  struct State;
  State &state;
  pTimer &p;
};

struct Window : private nall::base_from_member<pWindow&>, Object {
  static Window None;
  nall::function<void ()> onClose;
  nall::function<void (Keyboard::Keycode)> onKeyPress;
  nall::function<void (Keyboard::Keycode)> onKeyRelease;
  nall::function<void ()> onMove;
  nall::function<void ()> onSize;

  inline void append() {}
  inline void remove() {}
  template<typename T, typename... Args> void append(T &arg, Args&... args) { append_(arg); append(args...); }
  template<typename T, typename... Args> void remove(T &arg, Args&... args) { remove_(arg); remove(args...); }

  void append_(Layout &layout);
  void append_(Menu &menu);
  void append_(Widget &widget);
  Color backgroundColor();
  Geometry frameGeometry();
  Geometry frameMargin();
  bool focused();
  bool fullScreen();
  Geometry geometry();
  void ignore();
  void remove_(Layout &layout);
  void remove_(Menu &menu);
  void remove_(Widget &widget);
  void setBackgroundColor(const Color &color);
  void setFrameGeometry(const Geometry &geometry);
  void setFocused();
  void setFullScreen(bool fullScreen = true);
  void setGeometry(const Geometry &geometry);
  void setMenuFont(const nall::string &font);
  void setMenuVisible(bool visible = true);
  void setResizable(bool resizable = true);
  void setStatusFont(const nall::string &font);
  void setStatusText(const nall::string &text);
  void setStatusVisible(bool visible = true);
  void setTitle(const nall::string &text);
  void setVisible(bool visible = true);
  void setWidgetFont(const nall::string &font);
  nall::string statusText();
  void synchronizeLayout();
  bool visible();

  Window();
  ~Window();
  struct State;
  State &state;
  pWindow &p;
};

struct Action : Object {
  bool enabled();
  void setEnabled(bool enabled = true);
  void setVisible(bool visible = true);
  bool visible();

  Action(pAction &p);
  ~Action();
  struct State;
  State &state;
  pAction &p;
};

struct Menu : private nall::base_from_member<pMenu&>, Action {
  template<typename... Args> void append(Args&... args) { append({ args... }); }
  template<typename... Args> void remove(Args&... args) { remove({ args... }); }

  void append(const nall::array<Action&> &list);
  void remove(const nall::array<Action&> &list);
  void setImage(const nall::image &image);
  void setText(const nall::string &text);

  Menu();
  ~Menu();
  struct State;
  State &state;
  pMenu &p;
};

struct Separator : private nall::base_from_member<pSeparator&>, Action {
  Separator();
  ~Separator();
  pSeparator &p;
};

struct Item : private nall::base_from_member<pItem&>, Action {
  nall::function<void ()> onActivate;

  void setImage(const nall::image &image);
  void setText(const nall::string &text);

  Item();
  ~Item();
  struct State;
  State &state;
  pItem &p;
};

struct CheckItem : private nall::base_from_member<pCheckItem&>, Action {
  nall::function<void ()> onToggle;

  bool checked();
  void setChecked(bool checked = true);
  void setText(const nall::string &text);

  CheckItem();
  ~CheckItem();
  struct State;
  State &state;
  pCheckItem &p;
};

struct RadioItem : private nall::base_from_member<pRadioItem&>, Action {
  template<typename... Args> static void group(Args&... args) { group({ args... }); }
  static void group(const nall::array<RadioItem&> &list);

  nall::function<void ()> onActivate;

  bool checked();
  void setChecked();
  void setText(const nall::string &text);

  RadioItem();
  ~RadioItem();
  struct State;
  State &state;
  pRadioItem &p;
};

struct Sizable : Object {
  virtual bool enabled() = 0;
  Layout* layout();
  virtual Geometry minimumGeometry() = 0;
  virtual void setEnabled(bool enabled = true) = 0;
  virtual void setGeometry(const Geometry &geometry) = 0;
  virtual void setVisible(bool visible = true) = 0;
  virtual bool visible() = 0;
  Window* window();

  Sizable(pSizable &p);
  ~Sizable();
  struct State;
  State &state;
  pSizable &p;
};

struct Layout : private nall::base_from_member<pLayout&>, Sizable {
  virtual void append(Sizable &sizable);
  virtual void remove(Sizable &sizable);
  virtual void reset() {}
  virtual void synchronizeLayout() = 0;

  Layout();
  Layout(pLayout &p);
  ~Layout();
  struct State;
  State &state;
  pLayout &p;
};

struct Widget : private nall::base_from_member<pWidget&>, Sizable {
  bool enabled();
  nall::string font();
  Geometry geometry();
  Geometry minimumGeometry();
  void setEnabled(bool enabled = true);
  void setFocused();
  void setFont(const nall::string &font);
  void setGeometry(const Geometry &geometry);
  void setVisible(bool visible = true);
  bool visible();

  Widget();
  Widget(pWidget &p);
  ~Widget();
  struct State;
  State &state;
  pWidget &p;
};

struct Button : private nall::base_from_member<pButton&>, Widget {
  nall::function<void ()> onActivate;

  void setImage(const nall::image &image, Orientation = Orientation::Horizontal);
  void setText(const nall::string &text);

  Button();
  ~Button();
  struct State;
  State &state;
  pButton &p;
};

struct Canvas : private nall::base_from_member<pCanvas&>, Widget {
  nall::function<void ()> onMouseLeave;
  nall::function<void (Position)> onMouseMove;
  nall::function<void (Mouse::Button)> onMousePress;
  nall::function<void (Mouse::Button)> onMouseRelease;

  uint32_t* data();
  bool setImage(const nall::image &image);
  void setSize(const Size &size);
  Size size();
  void update();

  Canvas();
  ~Canvas();
  struct State;
  State &state;
  pCanvas &p;
};

struct CheckBox : private nall::base_from_member<pCheckBox&>, Widget {
  nall::function<void ()> onToggle;

  bool checked();
  void setChecked(bool checked = true);
  void setText(const nall::string &text);

  CheckBox();
  ~CheckBox();
  struct State;
  State &state;
  pCheckBox &p;
};

struct ComboBox : private nall::base_from_member<pComboBox&>, Widget {
  nall::function<void ()> onChange;

  template<typename... Args> void append(const Args&... args) { append_({ args... }); }

  void append_(const nall::lstring &list);
  void reset();
  unsigned selection();
  void setSelection(unsigned row);

  ComboBox();
  ~ComboBox();
  struct State;
  State &state;
  pComboBox &p;
};

struct HexEdit : private nall::base_from_member<pHexEdit&>, Widget {
  nall::function<uint8_t (unsigned)> onRead;
  nall::function<void (unsigned, uint8_t)> onWrite;

  void setColumns(unsigned columns);
  void setLength(unsigned length);
  void setOffset(unsigned offset);
  void setRows(unsigned rows);
  void update();

  HexEdit();
  ~HexEdit();
  struct State;
  State &state;
  pHexEdit &p;
};

struct HorizontalScrollBar : private nall::base_from_member<pHorizontalScrollBar&>, Widget {
  nall::function<void ()> onChange;

  unsigned length();
  unsigned position();
  void setLength(unsigned length);
  void setPosition(unsigned position);

  HorizontalScrollBar();
  ~HorizontalScrollBar();
  struct State;
  State &state;
  pHorizontalScrollBar &p;
};

struct HorizontalSlider : private nall::base_from_member<pHorizontalSlider&>, Widget {
  nall::function<void ()> onChange;

  unsigned length();
  unsigned position();
  void setLength(unsigned length);
  void setPosition(unsigned position);

  HorizontalSlider();
  ~HorizontalSlider();
  struct State;
  State &state;
  pHorizontalSlider &p;
};

struct Label : private nall::base_from_member<pLabel&>, Widget {
  void setText(const nall::string &text);

  Label();
  ~Label();
  struct State;
  State &state;
  pLabel &p;
};

struct LineEdit : private nall::base_from_member<pLineEdit&>, Widget {
  nall::function<void ()> onActivate;
  nall::function<void ()> onChange;

  void setEditable(bool editable = true);
  void setText(const nall::string &text);
  nall::string text();

  LineEdit();
  ~LineEdit();
  struct State;
  State &state;
  pLineEdit &p;
};

struct ListView : private nall::base_from_member<pListView&>, Widget {
  nall::function<void ()> onActivate;
  nall::function<void ()> onChange;
  nall::function<void (unsigned)> onToggle;

  template<typename... Args> void append(const Args&... args) { append_({ args... }); }
  template<typename... Args> void modify(unsigned row, const Args&... args) { modify_(row, { args... }); }
  template<typename... Args> void setHeaderText(const Args&... args) { setHeaderText_({ args... }); }

  void append_(const nall::lstring &list);
  void autoSizeColumns();
  bool checked(unsigned row);
  void modify_(unsigned row, const nall::lstring &list);
  void reset();
  bool selected();
  unsigned selection();
  void setCheckable(bool checkable = true);
  void setChecked(unsigned row, bool checked = true);
  void setHeaderText_(const nall::lstring &list);
  void setHeaderVisible(bool visible = true);
  void setSelected(bool selected = true);
  void setSelection(unsigned row);

  ListView();
  ~ListView();
  struct State;
  State &state;
  pListView &p;
};

struct ProgressBar : private nall::base_from_member<pProgressBar&>, Widget {
  void setPosition(unsigned position);

  ProgressBar();
  ~ProgressBar();
  struct State;
  State &state;
  pProgressBar &p;
};

struct RadioBox : private nall::base_from_member<pRadioBox&>, Widget {
  template<typename... Args> static void group(Args&... args) { group({ args... }); }
  static void group(const nall::array<RadioBox&> &list);

  nall::function<void ()> onActivate;

  bool checked();
  void setChecked();
  void setText(const nall::string &text);

  RadioBox();
  ~RadioBox();
  struct State;
  State &state;
  pRadioBox &p;
};

struct TextEdit : private nall::base_from_member<pTextEdit&>, Widget {
  nall::function<void ()> onChange;

  void setCursorPosition(unsigned position);
  void setEditable(bool editable = true);
  void setText(const nall::string &text);
  void setWordWrap(bool wordWrap = true);
  nall::string text();

  TextEdit();
  ~TextEdit();
  struct State;
  State &state;
  pTextEdit &p;
};

struct VerticalScrollBar : private nall::base_from_member<pVerticalScrollBar&>, Widget {
  nall::function<void ()> onChange;

  unsigned length();
  unsigned position();
  void setLength(unsigned length);
  void setPosition(unsigned position);

  VerticalScrollBar();
  ~VerticalScrollBar();
  struct State;
  State &state;
  pVerticalScrollBar &p;
};

struct VerticalSlider : private nall::base_from_member<pVerticalSlider&>, Widget {
  nall::function<void ()> onChange;

  unsigned length();
  unsigned position();
  void setLength(unsigned length);
  void setPosition(unsigned position);

  VerticalSlider();
  ~VerticalSlider();
  struct State;
  State &state;
  pVerticalSlider &p;
};

struct Viewport : private nall::base_from_member<pViewport&>, Widget {
  nall::function<void ()> onMouseLeave;
  nall::function<void (Position)> onMouseMove;
  nall::function<void (Mouse::Button)> onMousePress;
  nall::function<void (Mouse::Button)> onMouseRelease;

  uintptr_t handle();

  Viewport();
  ~Viewport();
  pViewport &p;
};

#include "layout/fixed-layout.hpp"
#include "layout/horizontal-layout.hpp"
#include "layout/vertical-layout.hpp"
