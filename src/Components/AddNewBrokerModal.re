%raw
{|
  require("./AddNewBrokerModal.sass")
|};

[@react.component]
let make = (~isOpen, ~onClose) => {
    open RootReducer;
    let dispatch = StalkExchangeStore.useDispatch();
    let (brokerName, setBrokerName) = React.useState(() => "");
    let clearName = () => setBrokerName(_ => "");
    let onCancel = _ => { 
        onClose(); 
        clearName();
    };

    <Modal isOpen className="add-new-broker-modal">
        <h2 className="add-new-broker-modal__title">"Add New Stalk Broker" -> React.string</h2>
        <form 
            className="add-new-broker-modal__form"
            onSubmit={(event) => {
                ReactEvent.Form.stopPropagation(event);
                ReactEvent.Form.preventDefault(event);

                dispatch(MarketAction(AddNewBroker(brokerName)))
                clearName();
            }}
        >
            <div className="form__body"> 
                <input className="form__broker-name-input" placeholder="Broker Name" value=brokerName type_="text" onChange={(event) => {
                    let name = ReactEvent.Form.target(event)##value;

                    setBrokerName(_ => name);
                }} />
            </div>
            <div className="form__actions">
                <button className="form__cancel-button" type_="button" onClick=onCancel>"Cancel" -> React.string</button>
                <button className="form__submit-button" disabled={brokerName == ""}>
                    "Save" -> React.string
                </button>
            </div>
        </form>
    </Modal>
}