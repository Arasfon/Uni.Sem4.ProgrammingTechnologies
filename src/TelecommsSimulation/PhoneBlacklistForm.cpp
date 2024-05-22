#include "pch.h"

#include "PhoneBlacklistForm.h"

using namespace System::Collections::Specialized;

namespace TelecommsSimulation
{
    PhoneBlacklistForm::PhoneBlacklistForm(Core::PhoneWithBlacklist^ phoneWithBlacklist)
    {
        InitializeComponent();

        _phoneWithBlacklist = phoneWithBlacklist;

        // ReSharper disable CppObjectMemberMightNotBeInitialized
        NumberLabel->Text = _phoneWithBlacklist->Number;

        _phoneWithBlacklist->Blacklist->CollectionChanged += gcnew NotifyCollectionChangedEventHandler(
            this, &PhoneBlacklistForm::OnBlacklistChanged);
        // ReSharper restore CppObjectMemberMightNotBeInitialized
    }

    void PhoneBlacklistForm::AddToBlacklistButton_Click(Object^ sender, EventArgs^ e)
    {
        _phoneWithBlacklist->Blacklist->TryAdd(AddToBlacklistNumberTextBox->Text);
        AddToBlacklistNumberTextBox->Clear();
    }

    void PhoneBlacklistForm::RemoveSelectedFromBlacklistButton_Click(Object^ sender, EventArgs^ e)
    {
        _phoneWithBlacklist->Blacklist->TryRemove(safe_cast<String^>(BlacklistListBox->SelectedItem));
    }
}


void TelecommsSimulation::PhoneBlacklistForm::OnBlacklistChanged(Object^ sender, NotifyCollectionChangedEventArgs^ e)
{
    if (BlacklistListBox->InvokeRequired)
    {
        BlacklistListBox->Invoke(
            gcnew Action<Object^, NotifyCollectionChangedEventArgs^>(this, &PhoneBlacklistForm::OnBlacklistChanged),
            sender, e);
    }
    else
    {
        switch (e->Action)
        {
            case NotifyCollectionChangedAction::Add:
                {
                    for each (Object^ item in e->NewItems)
                    {
                        BlacklistListBox->Items->Add(item);
                    }
                    break;
                }
            case NotifyCollectionChangedAction::Remove:
                {
                    for each (Object^ item in e->OldItems)
                    {
                        BlacklistListBox->Items->Remove(item);
                    }
                    break;
                }
            case NotifyCollectionChangedAction::Reset:
                {
                    BlacklistListBox->Items->Clear();
                    break;
                }
            default:
                break;
        }
    }
}
