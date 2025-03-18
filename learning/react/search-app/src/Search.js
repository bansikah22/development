import React, { useState } from "react";
import data from './data'

const Search = () => {
    const [filter, setFilter] = useState('')

    const searchText = (event) => {
        setFilter(event.target.value);
    }

    let dataSearch = data.cardData.filter(item => {
        return item.title.toLowerCase().includes(filter.toLowerCase()) ||
               item.desc.toLowerCase().includes(filter.toLowerCase());
    });

    return (
        <section className="py-4 container">
            <div className="row justify-content-center">
                <div className="col-12 mb-5">
                    <div className="mb-3 col-4 mx-auto text-center">
                        <label className="form-label h4">Search</label>
                        <input
                            type="text"
                            className="form-control"
                            value={filter}
                            onChange={searchText}
                            placeholder="Search by title or description..."
                        />
                    </div>
                </div>

                {dataSearch.map((item) => (
                    <div key={item.id} className="col-11 col-md-6 col-lg-3 mx-0 mb-4">
                        <div className="card p-0 overflow-hidden h-100 shadow">
                            <img src={item.img} className="card-img-top" alt={item.title} />
                            <div className="card-body">
                                <h5 className="card-title">{item.title}</h5>
                                <p className="card-text">{item.desc}</p>
                            </div>
                        </div>
                    </div>
                ))}
            </div>
        </section>
    )
}

export default Search;