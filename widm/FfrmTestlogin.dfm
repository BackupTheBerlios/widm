object frmTestLogin: TfrmTestLogin
  Left = 245
  Top = 486
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Voer naam in'
  ClientHeight = 154
  ClientWidth = 317
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Comic Sans MS'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 29
  object Label1: TLabel
    Left = 16
    Top = 32
    Width = 55
    Height = 29
    Caption = 'Naam'
  end
  object Button1: TButton
    Left = 48
    Top = 96
    Width = 233
    Height = 41
    Caption = 'Naam ingevuld'
    Default = True
    TabOrder = 1
    OnClick = Button1Click
  end
  object txtName: TEdit
    Left = 104
    Top = 24
    Width = 193
    Height = 37
    TabOrder = 0
  end
end
